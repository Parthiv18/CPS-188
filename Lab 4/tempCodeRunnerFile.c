#include <math.h>
#include <stdio.h>

/*
Pascal Triangle
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
*/

int main() {
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);
    for (int i = 0; i <= size; i++) {
        /*for (int k = 0; k <= (size - i); k++) {
            printf(" ");
        }*/
        int value = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", value);
            value = (value * (i - j) / (j + 1));  // formula
        }
        printf("\n");
    }
    return 0;
}