#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        FILE *fp = fopen("sensor_input.txt", "r");
        if (!fp) {
            perror("sensor_input.txt");
            return 1;
        }

        int ch0, ch1, ch2, ch3;

        if (fscanf(fp, "%d,%d,%d,%d", &ch0, &ch1, &ch2, &ch3) == 4) {
            printf("CH0(IR): %d | CH1(Visible): %d | CH2(Blue/Green): %d | CH3(Red/NIR): %d\n",
                   ch0, ch1, ch2, ch3);
        }

        fclose(fp);

        usleep(200000); // 5Hz
    }

    return 0;
}

