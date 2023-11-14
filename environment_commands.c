#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * handle_setenv - Set or modify an environment variable
 * @variable: Name of the environment variable
 * @value: Value to set for the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int handle_setenv(char *variable, char *value)
{
    int result;

    if (variable == NULL || value == NULL)
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return -1;
    }

    result = setenv(variable, value, 1);

    if (result == -1)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}

/**
 * handle_unsetenv - Unset an environment variable
 * @variable: Name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int handle_unsetenv(char *variable)
{
    int result;

    if (variable == NULL)
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return -1;
    }

    result = unsetenv(variable);

    if (result == -1)
    {
        perror("unsetenv");
        return -1;
    }

    return 0;
}
