#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {          // loop size of array
        for (int j = i; j < 4 - 1; j++) {  // loop one more
            printf("%d %d\n", arr[i], arr[j]);
        }
    }
    // printf("\n%d", counter); //4
    // printf("\n%d", arr[5]); //size 4 so max 4
}