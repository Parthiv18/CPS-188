#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3-1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int n;

    printf("How many numbers you want to input?: ");
    scanf("%d", &n);

    int store[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Numbers: ");
        scanf("%d", &store[i]);
    }
    
    return 0;
}