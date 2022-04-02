#include <stdio.h>
#include <stdlib.h>

//#include "mylibrary.h"
/*output to bin file*/

int main() {
    /*
        100 numbers -> [10][10]
    */
    FILE *fp = fopen("real.txt", "r");
    double arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; i < 10; j++) {
            fscanf(fp, "%lf", &arr[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; i < 10; j++) {
            printf("%lf\t", arr[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}