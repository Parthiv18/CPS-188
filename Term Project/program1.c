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
int freeze(double *arr, int total) {  // 8. freeze days counter
    int counter = 0;
    for (int i = 0; i < total; i++) {
        if (arr[i] < 0) {
            counter++;
        }
    }
    return counter;
}
int getTextFileLine() {
    FILE *fp = fopen("q1-8Data.txt", "r");
    int checker;
    int counter = 1;
    int nonCounter = 1;
    while (checker != EOF) {
        checker = fgetc(fp);
        if (checker == '\n')
            counter++;
    }
    return counter;
}

int main() {
    char line[1000];
    FILE *fp = fopen("q1-8Data.txt", "r");

    int tempSize = getTextFileLine();
    // printf("%d\n", getTextFileLine());

    // getting info
    int year[tempSize], day[tempSize];
    double sup[tempSize], mich[tempSize], huron[tempSize], erie[tempSize], ont[tempSize], stClr[tempSize];
    for (int i = 0; fscanf(fp, "%c", &line) != EOF; i++) {                                                                           // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
        // printf("%d : %.2lf\n", i, sup[i]);
    }

    // Header
    // printf("Lake\tAverage Temp\tWarmest Weather (date/month)\tColdest Weather (date/month)\tSummer Average\tWinter Average");

    // 1. average output
    printf("Average Temp: %.5lf\n", avg(ont, 0, tempSize));

    fclose(fp);

    return 0;
}