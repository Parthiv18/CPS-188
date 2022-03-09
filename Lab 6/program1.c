#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double formula(double min, double max, double xi, double xlow, double xhigh) {
    return min + (xi - xlow) * (max - min) / xhigh - xlow;
}

int main() {
    char line[1000];
    FILE *fp = fopen("data.txt", "r");

    double *arr;

    for (int i = 0; fscanf(fp, "%c", &line) != EOF; i++) {
        fscanf(fp, "%lf. ", &arr[i]);
        printf("%.1lf ", arr[i]);
    }
    //printf("%lf", arr[0]);
    for (int i = 2; i < 7; i++) {  // change 7 accordingly after
        printf("%.2lf\n", formula(arr[0], arr[1], arr[i], 0, 7));
    }
}