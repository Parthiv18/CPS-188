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
int *sort(double arr[6], int size) {
    static int storeArr[6] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = storeArr[i];
                storeArr[i] = storeArr[j];
                storeArr[j] = temp;

                double temp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp2;
            }
        }
    }
    return storeArr;
}
/*Question 2*/
char *lakeStatus(double num, double target) {
    if (num > target) {
        return "Warm => Above Avg";
    } else {
        return "Cold => Below Avg";
    }
}
/*Question 3*/
void dates(int pos) {
    char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};  // make this enum
    if (pos >= 1 && pos <= 31) {
        printf("%s %d ", months[0], pos);
    } else if (pos >= 32 && pos <= 60) {
        printf("%s %d ", months[1], pos - 31);
    } else if (pos >= 32 && pos <= 91) {
        printf("%s %d ", months[2], pos - 60);
    } else if (pos >= 32 && pos <= 121) {
        printf("%s %d ", months[3], pos - 91);
    } else if (pos >= 32 && pos <= 152) {
        printf("%s %d ", months[4], pos - 121);
    } else if (pos >= 32 && pos <= 182) {
        printf("%s %d ", months[5], pos - 152);
    } else if (pos >= 32 && pos <= 213) {
        printf("%s %d ", months[6], pos - 182);
    } else if (pos >= 32 && pos <= 244) {
        printf("%s %d ", months[7], pos - 213);
    } else if (pos >= 32 && pos <= 274) {
        printf("%s %d ", months[8], pos - 244);
    } else if (pos >= 32 && pos <= 305) {
        printf("%s %d ", months[9], pos - 274);
    } else if (pos >= 32 && pos <= 335) {
        printf("%s %d ", months[10], pos - 305);
    } else {
        printf("%s %d ", months[11], pos - 335);
    }
}
double minVal(double *arr, int size) {
    double m = arr[0];
    for (int i = 0; i < size; i++) {
        if (m > arr[i]) {
            m = arr[i];
        }
    }
    return m;
}
double maxVal(double *arr, int size) {
    double m = arr[0];
    for (int i = 0; i < size; i++) {
        if (m < arr[i]) {
            m = arr[i];
        }
    }
    return m;
}
void warmDay(double *arr, int *day, int size, char *lakeName) {
    double max = maxVal(arr, size);
    printf("\n%s warmest temperature is %.2lf on ", lakeName, max);
    for (int i = 0; i < size; i++) {
        if (max == arr[i]) {
            dates(day[i]);
        }
    }
}
void coldDay(double *arr, int *day, int size, char *lakeName) {
    double min = minVal(arr, size);
    printf("\n%s coldest temperature is %.2lf on ", lakeName, min);
    for (int i = 0; i < size; i++) {
        if (min == arr[i]) {
            dates(day[i]);
        }
    }
}
/*Question 4*/
int search(double *arr, int size, double val) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (val == arr[i]) {
            counter = i;
        }
    }
    return counter + 1;  // since day starts at 1 not 0
}
/*Question 5*/
/*Question 6*/
// check code

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
double compareDiff(double num1, double num2) {
    if (num1 > num2) {
        return (num1 - num2);
    } else {
        return (num2 - num1);
    }
}
/*Getting Data*/
int getTextFileLine(char *fileName) {
    FILE *fp = fopen(fileName, "r");
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
void dataFile(int *year, int *day, double *sup, double *mich, double *huron, double *erie, double *ont, double *stClr, char *fileName) {
    char line[1000];
    FILE *fp = fopen(fileName, "r");
    for (int i = 0; i < getTextFileLine(fileName); i++) {                                                                            // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
    }
    fclose(fp);
}
/*Output*/
void q18Output() {
    // 2022 data
    int tempSize = getTextFileLine("q1-8Data.txt");
    int year[tempSize], day[tempSize];
    double sup[tempSize], mich[tempSize], huron[tempSize], erie[tempSize], ont[tempSize], stClr[tempSize];
    dataFile(year, day, sup, mich, huron, erie, ont, stClr, "q1-8Data.txt");
    // 2019 data
    int tempSize2019 = getTextFileLine("q9Data.txt");
    int year2019[tempSize2019], day2019[tempSize2019];
    double sup2019[tempSize2019], mich2019[tempSize2019], huron2019[tempSize2019], erie2019[tempSize2019], ont2019[tempSize2019], stClr2019[tempSize2019];
    dataFile(year2019, day2019, sup2019, mich2019, huron2019, erie2019, ont2019, stClr2019, "q9Data.txt");

    char *lakeArr[6] = {"Sup.", "Mich.", "Huron.", "Erie.", "Ont.", "StClr."};

    /*Question 1-2*/
    printf("Lake\t\tAverage\t\tTotal Avg\tStatus\n");
    double avgArr[6] = {avg(sup, 0, tempSize), avg(mich, 0, tempSize), avg(huron, 0, tempSize), avg(erie, 0, tempSize), avg(ont, 0, tempSize), avg(stClr, 0, tempSize)};
    int *indexArr = sort(avgArr, 6);
    double lakeAvg = totalAvg(avg(sup, 0, tempSize), avg(mich, 0, tempSize), avg(huron, 0, tempSize), avg(erie, 0, tempSize), avg(ont, 0, tempSize), avg(stClr, 0, tempSize), 6);
    printf("%s\t\t%.2lf\t\t%.2lf\t\t%s\tWarmest Lake\n", lakeArr[indexArr[0]], avgArr[0], lakeAvg, lakeStatus(avgArr[0], lakeAvg));
    printf("%s\t\t%.2lf\t\t\t\t%s\n", lakeArr[indexArr[1]], avgArr[1], lakeStatus(avgArr[1], lakeAvg));
    printf("%s\t\t%.2lf\t\t\t\t%s\n", lakeArr[indexArr[2]], avgArr[2], lakeStatus(avgArr[2], lakeAvg));
    printf("%s\t\t%.2lf\t\t\t\t%s\n", lakeArr[indexArr[3]], avgArr[3], lakeStatus(avgArr[3], lakeAvg));
    printf("%s\t\t%.2lf\t\t\t\t%s\n", lakeArr[indexArr[4]], avgArr[4], lakeStatus(avgArr[4], lakeAvg));
    printf("%s\t\t%.2lf\t\t\t\t%s\tColdest Lake\n", lakeArr[indexArr[5]], avgArr[5], lakeStatus(avgArr[5], lakeAvg));

    /*Question 3*/
    warmDay(sup, day, tempSize, "Sup.");
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
    coldDay(stClr, day, tempSize, "StClr.");

    /*Question 4 [yet to do]*/
    // overallWarm(sup, mich, huron, erie, ont, stClr, tempSize);
    double arr[6] = {maxVal(sup, tempSize), maxVal(mich, tempSize), maxVal(huron, tempSize), maxVal(erie, tempSize), maxVal(ont, tempSize), maxVal(stClr, tempSize)};
    int *arrIndex = sort(arr, 6);
    int warmPosIndex = search(erie, tempSize, arr[5]);
    int coldPosIndex = search(sup, tempSize, arr[0]);
    printf("\n\n%s %.2lf on ", lakeArr[arrIndex[4]], arr[5]);
    dates(warmPosIndex);
    printf("\n%s %.2lf on ", lakeArr[arrIndex[0]], arr[0]);
    dates(coldPosIndex);

    /*Question 5*/
    printf("\n\nLake\tSummer Average\tSummer Stats\t\n");
    double summerAvgArr[6] = {avg(sup, 172, 265), avg(mich, 172, 265), avg(huron, 172, 265), avg(erie, 172, 265), avg(ont, 172, 265), avg(stClr, 172, 265)};
    int *summerIndexArr = sort(summerAvgArr, 6);
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[0]], summerAvgArr[0], "No [check]");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[1]], summerAvgArr[1], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[2]], summerAvgArr[2], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[3]], summerAvgArr[3], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[4]], summerAvgArr[4], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[summerIndexArr[5]], summerAvgArr[5], "No");

    /*Question 6*/
    printf("\nLake\tWinter Average\tWinter Stats\t\n");
    double winterAvgArr[6] = {avg(sup, 1, 79) + avg(sup, 355, 365), avg(mich, 1, 79) + avg(mich, 355, 365), avg(huron, 1, 79) + avg(huron, 355, 365), avg(erie, 1, 79) + avg(erie, 355, 365), avg(ont, 1, 79) + avg(ont, 355, 365), avg(stClr, 1, 79) + avg(stClr, 355, 365)};
    int *winterIndexArr = sort(winterAvgArr, 6);
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[0]], winterAvgArr[0], "No [check]");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[1]], winterAvgArr[1], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[2]], winterAvgArr[2], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[3]], winterAvgArr[3], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[4]], winterAvgArr[4], "No");
    printf("%s\t%.2lf\t\t%s\n", lakeArr[winterIndexArr[5]], winterAvgArr[5], "No");

    /*Question 7-8*/
    printf("\nLake Name\tSwimming Total Days\tFreezing Total Days\n");
    printf("Sup.\t\t%d\t\t\t%d\n", swimming(sup, tempSize), freeze(sup, tempSize));
    printf("Mich.\t\t%d\t\t\t%d\n", swimming(mich, tempSize), freeze(mich, tempSize));
    printf("Huron.\t\t%d\t\t\t%d\n", swimming(huron, tempSize), freeze(huron, tempSize));
    printf("Erie.\t\t%d\t\t\t%d\n", swimming(erie, tempSize), freeze(erie, tempSize));
    printf("Ont.\t\t%d\t\t\t%d\n", swimming(ont, tempSize), freeze(ont, tempSize));
    printf("StClr.\t\t%d\t\t\t%d\n", swimming(stClr, tempSize), freeze(stClr, tempSize));

    /*Question 9*/
    printf("\nLake\t\tAverage(2019)\t\tAverage(2020)\t\tDifference\tTotal Avg(2019)\t\tTotal Avg(2020)\t\tDifference\n");
    double lakeAvg2019 = totalAvg(avg(sup2019, 0, tempSize), avg(mich2019, 0, tempSize), avg(huron2019, 0, tempSize), avg(erie2019, 0, tempSize), avg(ont2019, 0, tempSize), avg(stClr2019, 0, tempSize), 6);
    printf("Sup.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(sup2019, 0, tempSize2019), avg(sup, 0, tempSize), compareDiff(avg(sup2019, 0, tempSize2019), avg(sup, 0, tempSize)), lakeAvg2019, lakeAvg, compareDiff(lakeAvg2019, lakeAvg));
    printf("Mich.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(mich2019, 0, tempSize2019), avg(mich, 0, tempSize), compareDiff(avg(mich2019, 0, tempSize2019), avg(mich, 0, tempSize)));
    printf("Huron.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(huron2019, 0, tempSize2019), avg(huron, 0, tempSize), compareDiff(avg(huron2019, 0, tempSize2019), avg(huron, 0, tempSize)));
    printf("Erie.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(erie2019, 0, tempSize2019), avg(erie, 0, tempSize), compareDiff(avg(erie2019, 0, tempSize2019), avg(erie, 0, tempSize)));
    printf("Ont.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(ont2019, 0, tempSize2019), avg(ont, 0, tempSize), compareDiff(avg(ont2019, 0, tempSize2019), avg(ont, 0, tempSize)));
    printf("StClr.\t\t%.2lf\t\t\t%.2lf\t\t\t%.2lf\n", avg(stClr2019, 0, tempSize2019), avg(stClr, 0, tempSize), compareDiff(avg(stClr2019, 0, tempSize2019), avg(stClr, 0, tempSize)));
}
int main() {
    q18Output();
}