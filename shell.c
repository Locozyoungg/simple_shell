#include "shell.h"
#include <stdio.h>

/**
 * print_environment - Print the environment variables
 */
void print_environment(void)
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
