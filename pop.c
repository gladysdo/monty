#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pop_handler(stack_t **stack, unsigned int line_number)
{
    if (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        if (*stack)
        {
            (*stack)->prev = NULL;
        }
        free(temp);
    }
    else
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}
