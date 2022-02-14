#include <math.h>
#include <stdio.h>

double grossPay(int hour, double wage) {
    if (hour <= 15) {
        return hour * wage;
    } else if (hour > 15 && hour <= 25) {
        return hour * (wage * 1.05);
    } else if (hour > 25) {
        return hour * (wage * 1.10);
    }
}  // round to nearst cent

int main() {
    /*
        employee number (int)
        number of shifts (int)
        base wage rate (real)
        one number per shift => number of hours worked
    */

    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength]; /* not ISO 90 compatible */

    filePointer = fopen("L4_data.txt", "r");

    while (fgets(buffer, bufferLength, filePointer)) {
        printf("%s", buffer);
    }

    fclose(filePointer);

    return 0;
}