#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double avg(double *arr, int start, int end) {  // 1/5/6/7 Average
    double sum;
    int counter = 0;
    for (int i = start; i < end; i++) {  // loop to rundown total
        sum += arr[i];                   // add up values
        counter++;
    }
    return sum / counter;  // formula
}
double warmDay(double *arr, int total) {  // 2. warm day
    double warm = arr[0];
    for (int i = 1; i < total; i++) {
        if (arr[i] > warm) {
            warm = arr[i];  // getting value of warm day
        }
    }
    return warm;
}
double coldDay(double *arr, int total) {  // 2. cold day
    double cold = arr[0];
    for (int i = 1; i < total; i++) {
        if (arr[i] < cold) {
            cold = arr[i];  // getting value of cold day
        }
    }
    return cold;
}
int getTextFileLine() {
    // count file
}

int main() {
    char line[1000];
    FILE *fp = fopen("q1-8Data.txt", "r");

    // getting info
    int year[365], day[365];
    double sup[365], mich[365], huron[365], erie[365], ont[365], stClr[365];
    for (int i = 0; fscanf(fp, "%c", &line) != EOF; i++) {                                                                           // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
        printf("%d : %.2lf\n", i, sup[i]);
    }
    // 1. average output
    // printf("%.2lf\n", avg(sup, 0, 365));

    // 2. warm/cold day
    // printf("Sup: %.2lf | %.2lf\n", warmDay(sup, 365), coldDay(sup, 365));

    // 4

    // 5. Summer Average
    //  printf("%.2lf\n", avg(sup, start, end));

    // 6. Winter Average
    // double totalWinter = avg(sup, start, end) + avg(sup, start, end)
    //  printf("%.2lf\n", totalWinter);

    // 7

    // 8

    fclose(fp);

    return 0;
}