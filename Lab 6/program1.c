#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double formula(double min, double max, double xi, double xlow, double xhigh) {  // function for formula
    return min + (xi - xlow) * (max - min) / xhigh - xlow;
}

int main() {
    // var
    FILE *fp;
    fp = fopen("data.txt", "r");
    int start;
    double min;
    double max;
    double *num;

    // getting info
    fscanf(fp, "%d", &start);
    fscanf(fp, "%lf", &min);
    fscanf(fp, "%lf", &max);

    // printf("%d %.1lf %.1lf\n", start, min, max);

    for (int i = 3; i < start + 3; i++) {  // starts at 3 to skip the first 3 elements since those are scanned | ends at 3 to consider remaining elements
        fscanf(fp, "%lf ", &num[i]);       // scans values and puts it into an array
        // printf("%.1lf ", num[i]);
        printf("%.1lf ", formula(min, max, num[i], 0, start));  // output
    }
}