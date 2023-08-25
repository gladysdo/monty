#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top_s = -1;

void push_in(int value) 
{
    if (top_s < STACK_SIZE - 1) 
    {
        stack[++top_s] = value;
    } else 
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop() 
{
    if (top_s >= 0) {
        return stack[top_s--];
    } else {
        printf("L<line_number>: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}
