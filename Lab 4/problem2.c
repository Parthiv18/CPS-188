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

    // var
    char line[1000];
    FILE *fp = fopen("L4_data.txt", "r");

    int empNum, shift, hours;
    double wage;
    int sum = 0;

    printf("Employee Number\t Shifts\t\tWage\tHours Worked Gross Pay\n------------------------------------------------------------------\n");
    // scanning
    while (fscanf(fp, "%d %d %lf", &empNum, &shift, &wage) != EOF) {  // running a while loop till end of line
        for (int i = 0; i < shift; i++) {                             // we set i to 0 and run it shift number of times
            fscanf(fp, "%d", &hours);                                 // scan all the trailing hours
            // printf("%d\n", hours);
            sum += hours;  // getting the sum of all the sums for each empolyee
        }
        // printf("Employee Number: %d\tShifts: %d\tWage: %.2lf\tGross Pay: $%.2lf\n", empNum, shift, wage, grossPay(hours, wage));
        printf("\t%d |\t\t%d | \t%.2lf | \t%d | %.2lf\n", empNum, shift, wage, sum, grossPay(sum, wage));  // output        
        // sum is 0 for new empolyee
        sum = 0;
    }
    fclose(fp);

    return 0;
}