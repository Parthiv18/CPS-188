#include <stdio.h>
#include <stdlib.h>

#include "mylibrary.h"

int main() {
    /*
        100 numbers -> [10][10]
        output to bin file
    */
    double arr[10][10];
    FILE *fp = fopen("real.txt", "r");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(fp, "%lf ", &arr[i][j]);
        }
    }

    FILE *wp = fopen("binFile.bin", "wb+");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // fwrite(&arr, 1, 1, wp);
            fprintf(wp, "%.1lf\t", arr[i][j]);
        }
        fprintf(wp, "\n");
    }

    fprintf(wp, "\nsums all the numbers in the main diagonal of the array: %.2lf", sumdiag(arr));
    fprintf(wp, "\nsum of all: %.2lf", sumall(arr));
    fprintf(wp, "\naverage of the last (rightmost) column of the array: %.2lf", avright(arr));
    fprintf(wp, "\nsums the four corners of the array: %.2lf", corners(arr));
    fprintf(wp, "\nlargest number found in the antidiagonal: %.2lf", largeanti(arr));  // do this

    fclose(fp);

    return 0;
}