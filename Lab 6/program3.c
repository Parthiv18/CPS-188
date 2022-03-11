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

    int asciiVal = 65;
    for (int i = 0; i < STACK_SIZE; i++) {
        char c = asciiVal;
        push(s, c, &s_top, STACK_SIZE);
        printf("%c ", s[i]);
        asciiVal++;
    }
    printf("\n");
    //s[] = pop(s, &s_top);
    for (int i = 0; i < STACK_SIZE; i++) {        
        s[0] = pop(s, &s_top);
        printf("%c ", s[i]);
    }

    return (0);
}
