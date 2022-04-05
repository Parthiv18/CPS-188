#include <stdio.h>
#include <stdlib.h>

#include "mylibrary.h"
#define rows 10
#define cols 10

void saveToFile(int (*matrix)[rows][cols]) {
    // matrix as a pointer to a 2D array of integers
    printf("%d\n", sizeof *matrix);
}

int main(int argc, const char *argv[]) {
    int m1[rows][cols];
    double arr[10][10];
    FILE *fp = fopen("real.txt", "r");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(fp, "%lf ", &m1[i][j]);
        }
    }
    fclose(fp);
    int m2[rows][cols];

    saveToFile(&m1);  // passing the address of m1

    FILE *fout = fopen("test.bin", "wb");  // save
    fwrite(m1, sizeof(m1), 1, fout);
    fclose(fout);

    FILE *fin = fopen("test.bin", "rb");  // open
    fread(m2, sizeof(m2), 10 * 10, fin);
    fclose(fin);

    return 0;
}