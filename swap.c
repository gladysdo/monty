#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_handler(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
    else
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
