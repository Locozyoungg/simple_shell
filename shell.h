#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024

char *custom_getline(void);
void print_environment(void);

#endif /* SHELL_H */
