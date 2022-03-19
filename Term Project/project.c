#include <stdio.h>
#include <string.h>

/*
    avg =   {2.3, 5.3, 5.1, 1.2};
    ogPos = {0 , 1 , 2 , 3};
    lakes = {sup, mich, huron, erie};
    newPos = {3, 0, 2, 1};



*/
int *sort(double arr[6], int size) {
    static int storeArr[6] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = storeArr[i];
                storeArr[i] = storeArr[j];
                storeArr[j] = temp;

                double temp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp2;
            }
        }
    }
    return storeArr;
}

int main() {
    double avg[6] = {5.5, 2.2, 1, 23, 43, 12};
    char *lakes[3] = {"sup", "mich", "huron"};
    int *posArr = sort(avg, 6);

    for (int i = 0; i < 6; i++) {
        printf("%.2lf ", avg[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", posArr[i]);
    }
    return 0;
}