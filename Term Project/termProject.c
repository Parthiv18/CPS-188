#include <stdio.h>
#include <stdlib.h>

double avg(double *arr, int start, int end) {  // 1/5/6/7 Average
    double sum = 0;
    for (int i = start; i < end; i++) {  // loop to rundown total
        sum += arr[i];                   // add up values
    }
    return sum / (end - start);  // formula
}
double totalAvg(double sum, int total) {
    return sum / total;
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
void dataFile2020(int *year, int *day, double *sup, double *mich, double *huron, double *erie, double *ont, double *stClr, char *fileName) {
    char line[1000];
    FILE *fp = fopen(fileName, "r");
    for (int i = 0; i < getTextFileLine(); i++) {                                                                                    // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
    }
}
int main() {
    int tempSize = getTextFileLine();
    int year[tempSize], day[tempSize];
    double sup[tempSize], mich[tempSize], huron[tempSize], erie[tempSize], ont[tempSize], stClr[tempSize];

    dataFile2020(year, day, sup, mich, huron, erie, ont, stClr, "q1-8Data.txt");
    // printf("%d %.2lf", year[0], sup[0]);
}