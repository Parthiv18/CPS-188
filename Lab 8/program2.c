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

    /*Writing to bin file*/
    FILE *wb = fopen("results.bin", "wb");
    if (wb != NULL) {
        double output1 = sumdiag(arr);
        double output2 = sumall(arr);
        double output3 = avright(arr);
        double output4 = corners(arr);
        double output5 = largeanti(arr);
        fwrite(&output1, sizeof(output1), 1, wb);
        fwrite(&output2, sizeof(output2), 1, wb);
        fwrite(&output3, sizeof(output3), 1, wb);
        fwrite(&output4, sizeof(output4), 1, wb);
        fwrite(&output5, sizeof(output5), 1, wb);
        fclose(wb);
    } else {
        printf("Error writing");
    }

    /*Writing from bin file*/
    FILE *rb = fopen("results.bin", "rb");
    if (rb != NULL) {
        double output;
        fread(&output, sizeof(output), 1, rb);
        printf("sums all the numbers in the main diagonal of the array: %.1lf\n", output);
        fread(&output, sizeof(output), 1, rb);
        printf("sum of all: %.1lf\n", output);
        fread(&output, sizeof(output), 1, rb);
        printf("average of the last (rightmost) column of the array: %.1lf\n", output);
        fread(&output, sizeof(output), 1, rb);
        printf("sums the four corners of the array: %.1lf\n", output);
        fread(&output, sizeof(output), 1, rb);
        printf("largest number found in the antidiagonal: %.1lf\n", output);
        fclose(rb);
    } else {
        printf("Error reading");
    }
    return 0;
}