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
    char line[1000];
    FILE *fp = fopen("L4_data.txt", "r");

    int empNum, shift, hours;
    double wage;
    // scanning
    while (fscanf(fp, "%d %d %lf %d", &empNum, &shift, &wage, &hours) != EOF) {
        printf("Employee Number: %d\tShifts: %d\tWage: %.2lf\tGross Pay: $%.2lf\n", empNum, shift, wage, grossPay(hours, wage));
    }
    fclose(fp);

    return 0;
}