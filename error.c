#include "monty.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int user_error(void)
{
    fprintf(stderr, "Usage: program_name filename\n");
    return(EXIT_FAILURE);
}

int open_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: Usage: push integer\n", line_number);
    return(EXIT_FAILURE);
}

int file_error(char *file_name)
{
    fprintf(stderr, "Error: Can't open file %s\n", file_name);
    return(EXIT_FAILURE);
}

int malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}
