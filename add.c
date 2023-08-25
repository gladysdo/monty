#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

    if (*stack && (*stack)->next)
    {
        (*stack)->next->n += (*stack)->n;
        temp = *stack;
        *stack = (*stack)->next;
        if (*stack)
        {
            (*stack)->prev = NULL;
        }
        free(temp);
    }
    else
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
