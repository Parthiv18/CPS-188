#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double avg(double *arr, int start, int end) {  // 1/5/6/7 Average
    double sum = 0;
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

    // 1. Average
    printf("Average Temp (Sup): %.2lf\nAverage Temp (Mich): %.2lf\nAverage Temp (Huron): %.2lf\nAverage Temp (Erie): %.2lf\nAverage Temp (Ont): %.2lf\nAverage Temp (StrClr): %.2lf",
           avg(sup, 0, tempSize), avg(mich, 0, tempSize), avg(huron, 0, tempSize), avg(erie, 0, tempSize), avg(ont, 0, tempSize), avg(stClr, 0, tempSize));

    // 2. Warm and Cold Temp
    printf("\n\nWarmest Day (Sup): %.2lf\nWarmest Day (Mich): %.2lf\nWarmest Day (Huron): %.2lf\nWarmest Day (Erie): %.2lf\nWarmest Day (Ont): %.2lf\nWarmest Day (StrClr): %.2lf",
           warmDay(sup, tempSize), warmDay(mich, tempSize), warmDay(huron, tempSize), warmDay(erie, tempSize), warmDay(ont, tempSize), warmDay(stClr, tempSize));
    printf("\nColdest Day (Sup): %.2lf\nColdest Day (Mich): %.2lf\nColdest Day (Huron): %.2lf\nColdest Day (Erie): %.2lf\nColdest Day (Ont): %.2lf\nColdest Day (StrClr): %.2lf",
           coldDay(sup, tempSize), coldDay(mich, tempSize), coldDay(huron, tempSize), coldDay(erie, tempSize), coldDay(ont, tempSize), coldDay(stClr, tempSize));
    // 3. Find the day for warmest and coldest
    // 4. Find warmest day overall
    // 5. Summer Average [yet to do -> warmest to coolest]
    printf("\n\nSummer Average (Sup): %.2lf\nSummer Average (Mich): %.2lf\nSummer Average (Huron): %.2lf\nSummer Average (Erie): %.2lf\nSummer Average (Ont): %.2lf\nSummer Average (StrClr): %.2lf",
           avg(sup, 172, 265), avg(mich, 172, 265), avg(huron, 172, 265), avg(erie, 172, 265), avg(ont, 172, 265), avg(stClr, 172, 265));
    // 6. Winter Average [yet to do -> warmest to coolest]
    printf("\nWinter Average (Sup): %.2lf\nWinter Average (Mich): %.2lf\nWinter Average (Huron): %.2lf\nWinter Average (Erie): %.2lf\nWinter Average (Ont): %.2lf\nWinter Average (StrClr): %.2lf",
           avg(sup, 1, 79) + avg(sup, 355, 365), avg(mich, 1, 79) + avg(mich, 355, 365), avg(huron, 1, 79) + avg(huron, 355, 365), avg(erie, 1, 79) + avg(erie, 355, 365), avg(ont, 1, 79) + avg(ont, 355, 365), avg(stClr, 1, 79) + avg(stClr, 355, 365));
    // 7. Swimming
    // 8. Freezing
    printf("\n\nFrozen Lake (Sup): %d\nFrozen Lake (Mich): %d\nFrozen Lake (Huron): %d\nFrozen Lake (Erie): %d\nFrozen Lake (Ont): %d\nFrozen Lake (StrClr): %d",
           freeze(sup, tempSize), freeze(mich, tempSize), freeze(huron, tempSize), freeze(erie, tempSize), freeze(ont, tempSize), freeze(stClr, tempSize));

    fclose(fp);

    return 0;
}