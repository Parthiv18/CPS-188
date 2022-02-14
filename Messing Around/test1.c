#include <stdio.h>

int main() {
    /*int sum;
    printf("Enter Number ");
    scanf("%d", &sum);
    printf("%d", sum);*/

    // pointers => getting location
    int num = 44;
    printf("num is %d stored at address %d\n", num, &num);
    // pointer => declaring
    int val = 50;
    int *point = &val;
    printf("val pointer: %d\n", point);
    // pointer => array
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("array pointer: %d\n", ptr);
    // pointer => assigning new value
    int *pointing;
    int var = 55;
    pointing = &var;
    printf("Var Old: %d\n", var);
    *pointing = 44;
    printf("Var New: %d\n", var);

    return 0;
}