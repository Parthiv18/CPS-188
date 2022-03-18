#include <stdio.h>
#include <string.h>

/*
    avg =   {2.3, 5.3, 5.1, 1.2};
    ogPos = {0 , 1 , 2 , 3};
    lakes = {sup, mich, huron, erie};
    newPos = {3, 0, 2, 1};



*/

int main() {
    double avg[3][3] = {{5.2, 0}, {4.2, 1}, {1.2, 2}};
    char *lakes[3] = {"sup", "mich", "huron"};

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3 - 1; col++) {
            printf("%.2lf ", avg[row][col]);
        }
        printf("\n");
    }
    return 0;
}