#include <stdio.h>

int main() {
    /*int sum;
    printf("Enter Number ");
    scanf("%d", &sum);
    printf("%d", sum);*/

    // pointers => getting location
    int num = 44;
    int num1 = 44;
    printf("num at address: %d %d\n", &num, &num1);
    printf("num at address: %d %d\n", num, num1);

    // pointer => declaring
    int *point = &num;
    printf("pointer: %d\n", point);

    // pointer => array
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("array pointer: %d\n", ptr);

    return 0;
}