#include <stdio.h>
#include <stdlib.h>

#include "mylibrary.h"

int main() {
    double arr[10][10];
    FILE *fp = fopen("real.txt", "r");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(fp, "%lf ", &arr[i][j]);
        }
    }
    fclose(fp);

    FILE *wb = fopen("output.bin", "wb");
    fwrite(&arr, sizeof(double), 10 * 10, wb);
    fclose(wb);

    FILE *wr = fopen("output.bin", "rb");
    for (int i = 0; i < 10; i++)
        fread(arr[i], sizeof(*arr[i]), 10 * 10, wr);
    fclose(wb);

    /*fprintf(wp, "\nsums all the numbers in the main diagonal of the array: %.2lf", sumdiag(arr));
    fprintf(wp, "\nsum of all: %.2lf", sumall(arr));
    fprintf(wp, "\naverage of the last (rightmost) column of the array: %.2lf", avright(arr));
    fprintf(wp, "\nsums the four corners of the array: %.2lf", corners(arr));
    fprintf(wp, "\nlargest number found in the antidiagonal: %.2lf", largeanti(arr));  // do this*/
    return 0;
}