#include "monty.h"

/**
 * free global arr of string
 */

void free_tokens(void) {
    size_t index = 0;

    if (op_toks != NULL) {
        while (op_toks[index] != NULL) {
            free(op_toks[index]);
            index++;
        }
        free(op_toks);
    }
}
/**
 * lent of token
 */

unsigned int token_arr(void) 
{
    unsigned int toks_len = 0;
    unsigned int i;

    for (unsigned int i = 0; op_toks[i] != NULL; i++) {
        toks_len++;
    }

    return toks_len;
}

/**
 * check if line read from getlin 
 */
int empty_line(char *line, char *delims) {
    for (int i = 0; line[i]; i++) {
        int is_delim = 0;

        for (int j = 0; delims[j]; j++) {
            if (line[i] == delims[j]) {
                is_delim = 1;
                break;
            }
        }

        if (!is_delim) {
            return 0;
        }
    }

    return 1;
}
/**
 *
