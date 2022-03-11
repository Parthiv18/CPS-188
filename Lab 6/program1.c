#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double formula(double min, double max, double xi, double xlow, double xhigh) {
    return min + (xi - xlow) * (max - min) / xhigh - xlow;
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "r");
    int start;
    double min;
    double max;
    double *num;

    fscanf(fp, "%d", &start);
    fscanf(fp, "%lf", &min);
    fscanf(fp, "%lf", &max);

    // printf("%d %.1lf %.1lf\n", start, min, max);

    for (int i = 3; i < start + 3; i++) {
        fscanf(fp, "%lf ", &num[i]);
        // printf("%.1lf ", num[i]);
        printf("%.1lf ", formula(min, max, num[i], 0, start));
    }
}