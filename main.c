#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    stack.size = 0;
    char *bytecode_file = "bytecodes/000.m";
    parse_bytecode_file(bytecode_file);
    stack_t *stack = NULL;

    return 0;
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <bytecode-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_bytecode_file(argv[1]);
    push_handler(&stack)
    pop_handler(&stack); 
    pall_handler(&stack);

    return EXIT_SUCCESS;
}
