#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_handler(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    if (arg)
    {
        int value = atoi(arg);
        if (value || strcmp(arg, "0") == 0)
        {
            stack_t *new_node = malloc(sizeof(stack_t));
            if (!new_node)
            {
                fprintf(stderr, "Error: Memory allocation failed on line %u\n", line_number);
                exit(EXIT_FAILURE);
            }
            new_node->n = value;
            new_node->prev = NULL;
            new_node->next = *stack;

            if (*stack)
            {
                (*stack)->prev = new_node;
            }

            *stack = new_node;
        }
        else
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void pall_handler(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

