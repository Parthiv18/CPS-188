#include <stdio.h>
#include <stdlib.h>

void value(int *arr, int size) {  // recursive function
    if (size == 1) {              // base case
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int store = arr[i];   // store is num at arr[i]
            arr[i] = arr[i + 1];  // arr[i] will be same number as arr[i+1] if arr[i] is > than arr[i+1]
            arr[i + 1] = store;   // arr[i+1] will be arr[i] or store to redo sort
        }
    }
    value(arr, size - 1);  // going down array
}

int main() {
    int *num;                      // pointer
    for (int i = 0; i < 3; i++) {  // loop to get info
        printf("What are your values(3): ");
        scanf("%d", &num[i]);
    }
    value(num, 3);                                                    // recursive sorting
    printf("\nMin: %d\nMid: %d\nMax: %d\n", num[0], num[1], num[2]);  // output
    for (int i = 0; i < 3; i++) {
        printf("%d ", num[i]);  // output
    }

    return 0;
}