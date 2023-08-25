#include "monty.h"

void parse_bytecode_file(char *filename)
{
	char line[100];
	unsigned int line_number = 1;
        stack_t *stack = NULL;
        instruction_t instruction_s[];
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        char *opcode = strtok(line, " \t\n");
        if (opcode)
        {
            int i = 0;
            while (instruction_s[i].opcode)
            {
                if (strcmp(opcode, instruction_s[i].opcode) == 0)
                {
                    instruction_s[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
	    if (!instruction_s[i].opcode)
        {
            fprintf(stderr, "Error: Unknown opcode \"%s\" on line %u\n", opcode, line_number);
            exit(EXIT_FAILURE);
        }
        }
        line_number++;
    }

    fclose(file);
}
