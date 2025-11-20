#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>

#define I2C_DEV "/dev/i2c-4"   // change to your bus
#define OPT4048_ADDR 0x29

// Example register read function (modify registers per OPT4048 datasheet)
int i2c_write_reg(int fd, uint8_t reg, uint8_t val) {
    uint8_t buf[2] = { reg, val };
    if (write(fd, buf, 2) != 2) return -1;
    return 0;
}

int i2c_read_buf(int fd, uint8_t reg, uint8_t *buf, int len) {
    if (write(fd, &reg, 1) != 1) return -1;
    if (read(fd, buf, len) != len) return -1;
    return 0;
}

// Create unix domain socket and send readings to client
int send_to_client(const char *socket_path, const char *msg) {
    int s, rc;
    struct sockaddr_un addr;
    s = socket(AF_UNIX, SOCK_STREAM, 0);
    if (s < 0) return -1;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    rc = connect(s, (struct sockaddr*)&addr, sizeof(addr));
    if (rc < 0) { close(s); return -1; }
    write(s, msg, strlen(msg));
    close(s);
    return 0;
}

int main(void) {
    int fd = open(I2C_DEV, O_RDWR);
    if (fd < 0) { perror("open i2c"); return 1; }
    if (ioctl(fd, I2C_SLAVE, OPT4048_ADDR) < 0) { perror("ioctl"); close(fd); return 1; }

    // Example: configure sensor (integration time etc). Use OPT4048 datasheet regs.
    // i2c_write_reg(fd, REG_CONFIG, CONFIG_VALUE);

    // Socket path that Android app/agent will listen on
    const char *socket_path = "/data/local/tmp/opt4048.sock";

    while (1) {
        uint8_t buf[6];
        // Example: read 6-byte data (modify per device)
        if (i2c_read_buf(fd, 0x10, buf, 6) == 0) {
            // parse channels from buf
            int ch0 = (buf[0]<<8) | buf[1];
            int ch1 = (buf[2]<<8) | buf[3];
            int ch2 = (buf[4]<<8) | buf[5];

            char msg[128];
            snprintf(msg, sizeof(msg), "%d,%d,%d\n", ch0, ch1, ch2);
            send_to_client(socket_path, msg);
        }
        usleep(200000); // 5Hz sampling
    }
    close(fd);
    return 0;
}

