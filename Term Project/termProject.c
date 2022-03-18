#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Question 1*/
double avg(double *arr, int start, int end) {  // 1/5/6/7 Average
    double sum = 0;
    for (int i = start; i < end; i++) {  // loop to rundown total
        sum += arr[i];                   // add up values
    }
    return sum / (end - start);  // formula
}
double totalAvg(double num1, double num2, double num3, double num4, double num5, double num6, double total) {
    return (num1 + num2 + num3 + num4 + num5 + num6) / total;
}
// sort lakes -> nums

/*Question 2*/
char *lakeStatus(double num, double target) {  // question 2
    if (num > target) {
        return "Warm => Above Avg";
    } else {
        return "Cold => Below Avg";
    }
}
/*Question 3*/
char *getMonth(int pos) {
    int month = pos / 30.417;                                                                                 // stores position
    char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};  // make this enum
    return months[month];
}
int getDate(int pos) {
    return pos % 30;  // [have 2 days 2%30 2 so date is 2 (Jan 2)]
}
void warmDay(double *arr, int *day, int size, char *lakeName) {
    double max = arr[0];
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    printf("\n%s warmest temperature %.2lf ", lakeName, max);
    for (int i = 0; i < size; i++) {
        if (max == arr[i]) {
            // do something
            // int temp = day[i];
            printf("on %s %d ", getMonth(day[i]), getDate(day[i]));
        }
    }
}
void coldDay(double *arr, int *day, int size, char *lakeName) {
    double min = arr[0];
    for (int i = 0; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    printf("\n%s coldest temperature is %.2lf ", lakeName, min);
    for (int i = 0; i < size; i++) {
        if (min == arr[i]) {
            // do something
            // int temp = day[i];
            printf("on %s %d ", getMonth(day[i]), getDate(day[i]));
        }
    }
}
/*Question 4*/

/*Question 5*/
void summer(double num1, double num2, double num3, double num4, double num5, double num6, int size) {
    /*
    first part => sort from low warmesnt to high warmes [display name]
        sort num1-num6
        output accordinly
         char arr = {sup,mich,huron}
         arr1 = {supAvg,michAvg,huronAvg}
         arr2 = {huron,sup,mich}
    */
    double arr[6];
    arr[0] = num1;
    arr[1] = num2;
    arr[2] = num3;
    arr[3] = num4;
    arr[4] = num5;
    arr[5] = num6;
    // sort(arr, 6);
}

/*Question 6*/
// avg(sup, 1, 79) + avg(sup, 355, 365)
/*Question 7*/
int swimming(double *arr, int total) {  // 7. Swimming
    int counter = 0;
    for (int i = 0; i < total; i++) {
        if (arr[i] > 20) {
            counter++;
        }
    }
    return counter;
}
/*Question 8*/
int freeze(double *arr, int total) {  // 8. freeze days counter
    int counter = 0;
    for (int i = 0; i < total; i++) {
        if (arr[i] < 0) {
            counter++;
        }
    }
    return counter;
}
/*Question 9*/
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
    fclose(fp);
    return counter;
}
void dataFile2020(int *year, int *day, double *sup, double *mich, double *huron, double *erie, double *ont, double *stClr, char *fileName) {
    char line[1000];
    FILE *fp = fopen(fileName, "r");
    for (int i = 0; i < getTextFileLine(); i++) {                                                                                    // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
    }
    fclose(fp);
}
void q18Output() {
    int tempSize = getTextFileLine();
    int year[tempSize], day[tempSize];
    double sup[tempSize], mich[tempSize], huron[tempSize], erie[tempSize], ont[tempSize], stClr[tempSize];
    dataFile2020(year, day, sup, mich, huron, erie, ont, stClr, "q1-8Data.txt");

    // Output [do q4 and q9]
    double lakeAvg = totalAvg(avg(sup, 0, tempSize), avg(mich, 0, tempSize), avg(huron, 0, tempSize), avg(erie, 0, tempSize), avg(ont, 0, tempSize), avg(stClr, 0, tempSize), 6);
    printf("Lake\t\tAverage\t\tTotal Avg\tStatus\n");
    printf("Sup.\t\t%.2lf\t\t%.2lf\t\t%s\n", avg(sup, 0, tempSize), lakeAvg, lakeStatus(avg(sup, 0, tempSize), lakeAvg));
    printf("Mich.\t\t%.2lf\t\t\t\t%s\n", avg(mich, 0, tempSize), lakeStatus(avg(mich, 0, tempSize), lakeAvg));
    printf("Huron.\t\t%.2lf\t\t\t\t%s\n", avg(huron, 0, tempSize), lakeStatus(avg(huron, 0, tempSize), lakeAvg));
    printf("Erie.\t\t%.2lf\t\t\t\t%s\n", avg(erie, 0, tempSize), lakeStatus(avg(erie, 0, tempSize), lakeAvg));
    printf("Ont.\t\t%.2lf\t\t\t\t%s\n", avg(ont, 0, tempSize), lakeStatus(avg(ont, 0, tempSize), lakeAvg));
    printf("StClr.\t\t%.2lf\t\t\t\t%s\n", avg(stClr, 0, tempSize), lakeStatus(avg(stClr, 0, tempSize), lakeAvg));

    printf("\n");
    double arr[6] = {avg(sup, 0, tempSize), avg(mich, 0, tempSize), avg(huron, 0, tempSize), avg(erie, 0, tempSize), avg(ont, 0, tempSize), avg(stClr, 0, tempSize)};
    int *posArr = sort(arr, 6);
    for (int i = 0; i < 6; i++) {
        printf("%.2lf ", arr[posArr[i]]);
    }

    /*warmDay(sup, day, tempSize, "Sup.");
    coldDay(sup, day, tempSize, "Sup.");
    warmDay(mich, day, tempSize, "Mich.");
    coldDay(mich, day, tempSize, "Mich.");
    warmDay(huron, day, tempSize, "Huron.");
    coldDay(huron, day, tempSize, "Huron.");
    warmDay(erie, day, tempSize, "Erie.");
    coldDay(erie, day, tempSize, "Erie.");
    warmDay(ont, day, tempSize, "Ont.");
    coldDay(ont, day, tempSize, "Ont.");
    warmDay(stClr, day, tempSize, "StClr.");
    coldDay(stClr, day, tempSize, "StClr.");*/

    /*printf("\n\nLake Name\tSwimming Total Days\tFreezing Total Days\n");
    printf("Sup.\t\t%d\t\t\t%d\n", swimming(sup, tempSize), freeze(sup, tempSize));
    printf("Mich.\t\t%d\t\t\t%d\n", swimming(mich, tempSize), freeze(mich, tempSize));
    printf("Huron.\t\t%d\t\t\t%d\n", swimming(huron, tempSize), freeze(huron, tempSize));
    printf("Erie.\t\t%d\t\t\t%d\n", swimming(erie, tempSize), freeze(erie, tempSize));
    printf("Ont.\t\t%d\t\t\t%d\n", swimming(ont, tempSize), freeze(ont, tempSize));
    printf("StClr.\t\t%d\t\t\t%d\n", swimming(stClr, tempSize), freeze(stClr, tempSize));*/
}
int main() {
    q18Output();
    // printf("%d %.2lf", year[0], sup[0]);
}