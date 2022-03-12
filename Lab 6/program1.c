#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double min(double *arr, int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
double max(double *arr, int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
double formula(double min, double max, double xi, double xlow, double xhigh) {  // function for formula
    return min + (xi - xlow) * (max - min) / (xhigh - xlow);
}

int main() {
    // var
    FILE *fp;
    fp = fopen("data.txt", "r");
    int size;
    double low, high;

    // getting info
    fscanf(fp, "%d", &size);
    fscanf(fp, "%lf", &low);
    fscanf(fp, "%lf", &high);
    double num[size];  // setting array to size

    for (int i = 0; fscanf(fp, "%lf", &num[i]) != EOF; i++) {  // loop to run down until end of file
        printf("%.1lf ", num[i]);                              // printing normal array
    }
    printf("\nNormalized Array\n");
    for (int j = 0; j < size; j++) {
        printf("%.1lf ", formula(low, high, num[j], min(num, size), max(num, size)));
    }
}