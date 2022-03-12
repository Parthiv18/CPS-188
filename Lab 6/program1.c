#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double min(double *arr, int size) {  // min formula
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
double max(double *arr, int size) {  // max formula
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

    while (fscanf(fp, "%d %lf %lf", &size, &low, &high) != EOF) {  // while loop to run scan
        double num[size];                                          // assigning array to size given in data sheet
        for (int i = 0; i < size; i++) {                           // running down size number of times
            fscanf(fp, "%lf", &num[i]);                            // scanning values in array
        }
        printf("\nArray\t\tNormalized Array\n");                                             // header
        for (int k = 0; k < size; k++) {                                                     // looping
            printf("%.1lf \t\t", num[k]);                                                    // output
            printf("%.1lf \n", formula(low, high, num[k], min(num, size), max(num, size)));  // output
        }
    }
}