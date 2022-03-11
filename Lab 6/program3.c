#include <stdio.h>
#define STACK_EMPTY '0'
#define STACK_SIZE 20

void push(char stack[], /* input/output - the stack */
          char item,    /* input - data being pushed onto the stack */
          int *top,     /* input/output - pointer to top of stack */
          int max_size) /* input - maximum size of stack */
{
    if (*top < max_size - 1) {
        ++(*top);
        stack[*top] = item;
    }
}

char pop(char stack[], /* input/output - the stack */
         int *top)     /* input/output - pointer to top of stack */
{
    char item; /* value popped off the stack */

    if (*top >= 0) {
        item = stack[*top];
        --(*top);
    } else {
        item = STACK_EMPTY;
    }

    return (item);
}

int main(void) {
    char s[STACK_SIZE];
    int s_top = -1;  // stack is empty

    int asciiVal = 65;                      // value of A in ascii terms
    for (int i = 0; i < STACK_SIZE; i++) {  // looping stack size times too push to stack
        char c = asciiVal;                  // int to char meaning int to ascii value
        push(s, c, &s_top, STACK_SIZE);     // push elements to stack
        printf("%c ", s[i]);
        asciiVal++;  // inc ascii element
    }
    printf("\n");
    s[0] = pop(s, &s_top);
    for (int i = 0; i < STACK_SIZE; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}
