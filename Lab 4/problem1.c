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
    // var
    int size;

    // input
    printf("Enter Size: ");
    scanf("%d", &size);

    for (int i = 0; i <= size; i++) {             // first loop
        int value = 1;                            // starting the triangle
        for (int j = 0; j <= i; j++) {            // second loop
            printf("%d ", value);                 // base case
            value = (value * (i - j) / (j + 1));  // formula [4th line for example => (value=1 => 1((i=3-j=0)/j=0+1)) (value=3 => 3((i=3-j=1)/j=1+1))) so on
        }
        printf("\n");  // new line
    }
    return 0;
}