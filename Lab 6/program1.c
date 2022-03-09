#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double formula(double min, double max, double xi, double xlow, double xhigh) {
    return min + (xi - xlow) * (max - min) / xhigh - xlow;
}

int main() {
    char line[1000];
    FILE *fp = fopen("data.txt", "r");

    int size;
    double min;
    double max;
    // double num[size];

    for (int i = 0; fscanf(fp, "%c", &line) != EOF; i++) {
        fscanf(fp, "%d  %lf %lf", &size, &min, &max);
        printf("%lf", min);
    }
}