#include "shell.h"
#include <string.h>

int custom_tokenize(char *input, char delim, char *tokens[], int max_tokens) {
    int token_count = 0;
    char *token = strtok(input, &delim);

    while (token != NULL && token_count < max_tokens) {
        tokens[token_count++] = token;
        token = strtok(NULL, &delim);
    }

    return (token_count);
}
