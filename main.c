#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main_simple_shell(void)
{
    char input[MAX_INPUT_SIZE];

    while (1)
    {
        char *token;
        char *path = "/bin/";
        char *command;
        char *args[2];
        pid_t child_pid;
        int status;

        printf(":) ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        token = strtok(input, " ");
        if (token == NULL)
            continue;

        command = token;

        if (strcmp(command, "exit") == 0)
            break;

        if (strcmp(command, "env") == 0)
        {
            print_environment();
            continue;
        }

        token = strtok(NULL, " ");
        args[0] = command;
        args[1] = token;
        args[2] = NULL;

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Fork error");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            char *full_command = malloc(strlen(path) + strlen(command) + 1);

            if (full_command == NULL)
            {
                perror("Error");
                exit(EXIT_FAILURE);
            }

            strcpy(full_command, path);
            strcat(full_command, command);

            if (execve(full_command, args, NULL) == -1)
            {
                perror("Error");
                free(full_command);
                exit(EXIT_FAILURE);
            }

            free(full_command);
        }
        else
        {
            wait(&status);
        }
    }

    return (0);
}

#define MAX_INPUT_SIZE 1024

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void) {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf(":) ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        execute_commands(input);
    }

    return 0;
}
