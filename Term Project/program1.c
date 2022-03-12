#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// make enum
double avg(double *arr, int start, int end) {  // 1/5/6/7 Average
    double sum = 0;
    int counter = 0;
    for (int i = start; i < end; i++) {  // loop to rundown total
        sum += arr[i];                   // add up values
        counter++;
    }
    return sum / counter;  // formula
}
double totalAvg(double sum, int total) {
    return sum / total;
}
int warmDay(double *arr, int total) {  // 2. warm day
    double warm = arr[0];
    int checker = 0;
    for (int i = 1; i < total; i++) {
        if (arr[i] > warm) {
            warm = arr[i];  // getting value of warm day
            checker = i;
        }
    }
    return checker;
}
int coldDay(double *arr, int total) {  // 2. cold day
    double cold = arr[0];
    int checker = 0;
    for (int i = 1; i < total; i++) {
        if (arr[i] < cold) {
            cold = arr[i];  // getting value of warm day
            checker = i;
        }
    }
    return checker;
}
char *date(int pos) {          // date/month format [dd/mm/yy]
    int month = pos / 30.417;  // stores position
    // int days = pos % 30;
    // char *num[3];
    char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};  // make this enum
    return months[month];
}
int swimming(double *arr, int total) {  // 7. Swimming
    int counter = 0;
    for (int i = 0; i < total; i++) {
        if (arr[i] > 20) {
            counter++;
        }
    }
    return counter;
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
void question1To8(int *day, double *sup, double *mich, double *huron, double *erie, double *ont, double *stClr, int tempSize) {
    // 1/5/6 Average Questions
    printf("Lake Name\tAvg Temp\tSummer Avg\tWinter Avg\tTotal Avg\n");
    double lakeSum = avg(sup, 0, tempSize) + avg(mich, 0, tempSize) + avg(huron, 0, tempSize) + avg(erie, 0, tempSize) + avg(ont, 0, tempSize) + avg(stClr, 0, tempSize);
    printf("Sup.\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(sup, 0, tempSize), avg(sup, 172, 265), avg(sup, 1, 79) + avg(sup, 355, 365), totalAvg(lakeSum, 6));
    printf("Mich.\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(mich, 0, tempSize), avg(mich, 172, 265), avg(mich, 1, 79) + avg(mich, 355, 365));
    printf("Huron.\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(huron, 0, tempSize), avg(huron, 172, 265), avg(huron, 1, 79) + avg(huron, 355, 365));
    printf("Erie.\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(erie, 0, tempSize), avg(erie, 172, 265), avg(erie, 1, 79) + avg(erie, 355, 365));
    printf("Ont.\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(ont, 0, tempSize), avg(ont, 172, 265), avg(ont, 1, 79) + avg(ont, 355, 365));
    printf("StClr.\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", avg(stClr, 0, tempSize), avg(stClr, 172, 265), avg(stClr, 1, 79) + avg(stClr, 355, 365));
    // 2. Which lake is warmest and coldest based on avg [read more]
    printf("\nQ2. Which lake is warmest and coldest based on avg: Yet to do\n");

    // Warm and Cold QUestions
    printf("\nLake Name\tWarmest Day\tDate (Warm)\tColdest Day\tDate (cold)\n");
    printf("Sup.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", sup[warmDay(sup, tempSize)], date(day[warmDay(sup, tempSize)]), sup[coldDay(sup, tempSize)], date(day[coldDay(sup, tempSize)]));
    printf("Mich.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", mich[warmDay(mich, tempSize)], date(day[warmDay(mich, tempSize)]), mich[coldDay(mich, tempSize)], date(day[coldDay(mich, tempSize)]));
    printf("Huron.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", huron[warmDay(huron, tempSize)], date(day[warmDay(huron, tempSize)]), huron[coldDay(huron, tempSize)], date(day[coldDay(huron, tempSize)]));
    printf("Erie.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", erie[warmDay(erie, tempSize)], date(day[warmDay(erie, tempSize)]), erie[coldDay(erie, tempSize)], date(day[coldDay(erie, tempSize)]));
    printf("Ont.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", ont[warmDay(ont, tempSize)], date(day[warmDay(ont, tempSize)]), ont[coldDay(ont, tempSize)], date(day[coldDay(ont, tempSize)]));
    printf("StClr.\t\t%.2lf\t\t%s\t\t%.2lf\t\t%s\n", stClr[warmDay(stClr, tempSize)], date(day[warmDay(stClr, tempSize)]), stClr[coldDay(stClr, tempSize)], date(day[coldDay(stClr, tempSize)]));
    // 4. Find warmest and coldest day overall for all lakes
    printf("\nQ4. Warmmest And Coldest Day Overall: Yet to do\n");

    // 8. Freezing
    printf("\nLake Name\tSwimming Total Days\tFreezing Total Days\n");
    printf("Sup.\t\t%d\t\t\t%d\n", swimming(sup, tempSize), freeze(sup, tempSize));
    printf("Mich.\t\t%d\t\t\t%d\n", swimming(mich, tempSize), freeze(mich, tempSize));
    printf("Huron.\t\t%d\t\t\t%d\n", swimming(huron, tempSize), freeze(huron, tempSize));
    printf("Erie.\t\t%d\t\t\t%d\n", swimming(erie, tempSize), freeze(erie, tempSize));
    printf("Ont.\t\t%d\t\t\t%d\n", swimming(ont, tempSize), freeze(ont, tempSize));
    printf("StClr.\t\t%d\t\t\t%d\n", swimming(stClr, tempSize), freeze(stClr, tempSize));
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
    question1To8(day, sup, mich, huron, erie, ont, stClr, tempSize);

    fclose(fp);

    return 0;
}