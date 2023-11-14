#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024

char *custom_getline(void);
void print_environment(void);
int custom_tokenize(char *input, char delim, char *tokens[], int max_tokens);

#endif /* SHELL_H */
