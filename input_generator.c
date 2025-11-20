#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp = fopen("sensor_input.txt", "w");
    if (!fp) {
        perror("sensor_input.txt");
        return 1;
    }

    srand(time(NULL));

    int ch0 = rand() % 1048576;   // 20-bit range
    int ch1 = rand() % 1048576;
    int ch2 = rand() % 1048576;
    int ch3 = rand() % 1048576;

    fprintf(fp, "%d,%d,%d,%d\n", ch0, ch1, ch2, ch3);

    fclose(fp);
    return 0;
}

