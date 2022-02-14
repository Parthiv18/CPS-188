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

void output() {
    printf("\nEmp (1): (77621), Gross Pay: %.2lf\n", grossPay(35, 18.00));
    printf("Emp (2): (82010), Gross Pay: %.2lf\n", grossPay(16, 22.50));
    printf("Emp (3): (92390), Gross Pay: %.2lf\n", grossPay(46, 19.50));
    printf("Emp (4): (62396), Gross Pay: %.2lf\n", grossPay(12, 32.00));
    printf("Emp (5): (89320), Gross Pay: %.2lf\n", grossPay(9, 27.50));
    printf("Emp (6): (19089), Gross Pay: %.2lf\n", grossPay(43, 16.00));
    printf("Emp (7): (54209), Gross Pay: %.2lf\n", grossPay(64, 17.00));
    printf("Emp (8): (50630), Gross Pay: %.2lf\n", grossPay(32, 20.00));
}

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

    // testing
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d %d %lf %d", &empNum, &shift, &wage, &hours);
        //printf("%d %d %lf %d\n", empNum, shift, wage, hours);
        printf("Employee Number: %d , Shifts: %d , Wage: %.2lf , Gross Pay: \n", empNum, shift, wage);
    }

    // output();

    fclose(fp);

    return 0;
}