#include "shell.h"
#include <stdlib.h>

/**
 * handle_exit - Handles the exit command
 * @argument: The exit argument (optional)
 *
 * This function exits the shell with a specified status.
 * If no argument is provided, the exit status is 0.
 */
void handle_exit(char *argument)
{
    if (argument != NULL)
    {
        int exit_status = atoi(argument);
        exit(exit_status);
    }
    else
    {
        exit(0);
    }
}

/**
 * handle_cd - Handles the cd command
 * @argument: The cd argument (optional)
 *
 * This function changes the current working directory.
 * If no argument is provided, it changes to the home directory.
 * If the argument is "-", it changes to the previous working directory.
 */
void handle_cd(char *argument)
{
    char *new_dir;

    if (argument == NULL)
    {
        new_dir = getenv("HOME");
        if (new_dir == NULL)
        {
            fprintf(stderr, "cd: No home directory\n");
            return;
        }
    }
    else if (_strcmp(argument, "-") == 0)
    {
        new_dir = getenv("OLDPWD");
        if (new_dir == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return;
        }
        printf("%s\n", new_dir);
    }
    else
    {
        new_dir = argument;
    }

    if (chdir(new_dir) != 0)
    {
        perror("cd");
    }
    else
    {
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", getcwd(NULL, 0), 1);
    }
}

