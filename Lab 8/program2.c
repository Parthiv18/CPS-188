#include <stdio.h>
#include <stdlib.h>

//#include "mylibrary.h"

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

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%.1lf\t", arr[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}