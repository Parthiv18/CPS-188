#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Getting size*/
int getSize(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    int checker;
    int counter = 1;
    while (checker != EOF) {
        checker = fgetc(fp);
        if (checker == '\n')
            counter++;
    }
    fclose(fp);
    return counter;
}
/*Reading Data*/
void dataFile(int *year, int *day, double *sup, double *mich, double *huron, double *erie, double *ont, double *stClr, char *fileName) {
    char line[1000];
    FILE *fp = fopen(fileName, "r");
    for (int i = 0; i < getSize(fileName); i++) {                                                                                    // loop to run down until end of file
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &sup[i], &mich[i], &huron[i], &erie[i], &ont[i], &stClr[i]);  // scanning inputs
    }
    fclose(fp);
}
/*Question 1*/
double findAvg(double *arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
double totalAvg(double num1, double num2, double num3, double num4, double num5, double num6, double total) {
    return (num1 + num2 + num3 + num4 + num5 + num6) / total;
}
/*Question 2*/
void sort(double arr[], int size, int indexArr[]) {
    // static int indexArr[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int indexTemp = indexArr[i];
                indexArr[i] = indexArr[j];
                indexArr[j] = indexTemp;

                double arrTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = arrTemp;
            }
        }
    }
}
char *lakeStatus(double num, double target) {
    if (num > target) {
        return "Warm => Above Avg";
    } else {
        return "Cold => Below Avg";
    }
}
/*Question 3*/
double minVal(double *arr, int size) {
    double min = arr[0];
    for (int i = 0; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}
double maxVal(double *arr, int size) {
    double max = arr[0];
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
int *search(double *arr, int size, double target) {
    static int index[35];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (target == arr[i]) {
            counter++;
            index[counter] = i + 1;
        }
    }
    return index;
}
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
/*Question 5*/
double summerAverage(double *arr, int start, int end) {
    double sum = 0;
    for (int i = start; i < end; i++) {
        sum += arr[i];
    }
    return sum / (end - start);
}
void sort1(double arr[], int size, int indexArr[]) {
    // static int indexArr[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int indexTemp = indexArr[i];
                indexArr[i] = indexArr[j];
                indexArr[j] = indexTemp;

                double arrTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = arrTemp;
            }
        }
    }
}
/*Question 6*/
double winterAverage(double *arr, int size, int start, int end, int start1, int end1) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (i >= start && i < end) {
            sum += arr[i];
        }
        if (i >= start1 && i < end1) {
            sum += arr[i];
        }
    }
    return sum / 91;
}

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

int main() {
    // 2020 data
    int size = getSize("data2020.txt");
    int year[size], day[size];
    double sup[size], mich[size], huron[size], erie[size], ont[size], stClr[size];
    dataFile(year, day, sup, mich, huron, erie, ont, stClr, "data2020.txt");
    // 2019 data
    int size2019 = getSize("data2019.txt");
    int year2019[size2019], day2019[size2019];
    double sup2019[size2019], mich2019[size2019], huron2019[size2019], erie2019[size2019], ont2019[size2019], stClr2019[size2019];
    dataFile(year2019, day2019, sup2019, mich2019, huron2019, erie2019, ont2019, stClr2019, "data2019.txt");

    char *lake[6] = {"Sup.", "Mich.", "Huron.", "Erie.", "Ont.", "StClr."};

    /*Question 1*/
    double lakeAvg[6] = {findAvg(sup, size), findAvg(mich, size), findAvg(huron, size), findAvg(erie, size), findAvg(ont, size), findAvg(stClr, size)};
    double totalLakeAvg = totalAvg(findAvg(sup, size), findAvg(mich, size), findAvg(huron, size), findAvg(erie, size), findAvg(ont, size), findAvg(stClr, size), 6);
    int lakeAvgIndex[6] = {0, 1, 2, 3, 4, 5};
    sort(lakeAvg, 6, lakeAvgIndex);
    printf("Lake Name\tAverage Tempreture\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%.2lf\n", lake[lakeAvgIndex[i]], lakeAvg[i]);
    }
    printf("Total Average Tempreture: %.2lf\n", totalLakeAvg);

    /*Question 2*/
    printf("\nLake Name\tStatus\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%s\n", lake[lakeAvgIndex[i]], lakeStatus(lakeAvg[i], totalLakeAvg));
    }
    printf("Warmest Lake (Avg): %s [%.2lf]\nColdest Lake (Avg): %s [%.2lf]\n", lake[lakeAvgIndex[5]], lakeAvg[5], lake[lakeAvgIndex[0]], lakeAvg[0]);

    /*Question 3*/
    double warmLake[6] = {maxVal(sup, size), maxVal(mich, size), maxVal(huron, size), maxVal(erie, size), maxVal(ont, size), maxVal(stClr, size)};
    int warmLakeIndex[6] = {0, 1, 2, 3, 4, 5};
    sort(warmLake, 6, warmLakeIndex);
    printf("\nLake Name\tWarmnest Tempreture\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%.2lf\n", lake[warmLakeIndex[i]], warmLake[i]);
    }  // DO DATES

    double coldLake[6] = {minVal(sup, size), minVal(mich, size), minVal(huron, size), minVal(erie, size), minVal(ont, size), minVal(stClr, size)};
    int coldLakeIndex[6] = {0, 1, 2, 3, 4, 5};
    sort(coldLake, 6, coldLakeIndex);
    printf("\nLake Name\tColdest Tempreture\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%.2lf\n", lake[coldLakeIndex[i]], coldLake[i]);
    }  // DO DATES
    printf("\n%s\t\t%.2lf", lake[coldLakeIndex[0]], coldLake[0]);

    /*Question 4*/
    printf("\nWarmnest Temperature: %s [%.2lf] on ", lake[warmLakeIndex[5]], warmLake[5]);
    int *warmDate = search(erie, size, warmLake[5]);
    for (int i = 0; i < 35; i++) {
        if (warmDate[i] != 0)
            dates(warmDate[i]);
    }
    printf("\nColdest Temperature: %s [%.2lf] on ", lake[coldLakeIndex[0]], coldLake[0]);
    int *coldDate = search(stClr, size, coldLake[0]);
    for (int i = 0; i < 35; i++) {
        if (coldDate[i] != 0)
            dates(coldDate[i]);
        // printf("%d ", dates(warmDate[i]));
    }
    /*Question 5*/
    double summerAvg[6] = {summerAverage(sup, 172 - 1, 265), summerAverage(mich, 172 - 1, 265), summerAverage(huron, 172 - 1, 265), summerAverage(erie, 172 - 1, 265), summerAverage(ont, 172 - 1, 265), summerAverage(stClr, 172 - 1, 265)};
    int summerAvgIndex[6] = {0, 1, 2, 3, 4, 5};
    sort1(summerAvg, 6, summerAvgIndex);  // sort1 is max - min
    printf("\n\nLake Name\tSummer Average Tempreture\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%.2lf\n", lake[summerAvgIndex[i]], summerAvg[i]);
    }

    /*Question 6*/
    double winterAvg[6] = {winterAverage(sup, size, 1 - 1, 79, 355 - 1, 366), winterAverage(mich, size, 1 - 1, 79, 355 - 1, 366), winterAverage(huron, size, 1 - 1, 79, 355 - 1, 366), winterAverage(erie, size, 1 - 1, 79, 355 - 1, 366), winterAverage(ont, size, 1 - 1, 79, 355 - 1, 366), winterAverage(stClr, size, 1 - 1, 79, 355 - 1, 366)};
    int winterAvgIndex[6] = {0, 1, 2, 3, 4, 5};
    sort(winterAvg, 6, winterAvgIndex);
    printf("\nLake Name\tWinter Average Tempreture\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\t\t%.2lf\n", lake[winterAvgIndex[i]], winterAvg[i]);
    }

    /*Question 7*/
    printf("\nLake Name\tSwimming Total Days\n");
    printf("Sup.\t\t%d\n", swimming(sup, size));
    printf("Mich.\t\t%d\n", swimming(mich, size));
    printf("Huron.\t\t%d\n", swimming(huron, size));
    printf("Erie.\t\t%d\n", swimming(erie, size));
    printf("Ont.\t\t%d\n", swimming(ont, size));
    printf("StClr.\t\t%d\n", swimming(stClr, size));

    /*Question 8*/
    printf("\nLake Name\tFreezing Total Days\n");
    printf("Sup.\t\t%d\n", freeze(sup, size));
    printf("Mich.\t\t%d\n", freeze(mich, size));
    printf("Huron.\t\t%d\n", freeze(huron, size));
    printf("Erie.\t\t%d\n", freeze(erie, size));
    printf("Ont.\t\t%d\n", freeze(ont, size));
    printf("StClr.\t\t%d\n", freeze(stClr, size));

    /*Question 9*/

    return 0;
}