#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
} 

int main()
{
    int n;

    printf("How many numbers you want to input?: ");
    scanf("%d", &n);

    int store[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Numbers: ");
        scanf("%d", &store[i]);
    }

    bubbleSort(store, sizeof(store) / 4);
    for (int i = 0; i < sizeof(store) / 4; i++) {
        printf("%d ", store[i]);
    }
    return 0;
}