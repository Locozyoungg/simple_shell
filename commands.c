#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a single command
 * @command: The command to be executed
 */
void execute_command(char *command) {
    char *token;
    char *path = "/bin/";
    char *args[3];
    int status;
    pid_t child_pid;

    token = strtok(command, " ");
    if (token == NULL)
        return;

    args[0] = token;

    token = strtok(NULL, " ");
    args[1] = token;

    args[2] = NULL;

    child_pid = fork();

    if (child_pid == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        char *full_command = malloc(strlen(path) + strlen(args[0]) + 1);
        if (full_command == NULL) {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        strcpy(full_command, path);
        strcat(full_command, args[0]);

        if (execve(full_command, args, NULL) == -1) {
            perror("Error");
            free(full_command);
            exit(EXIT_FAILURE);
        }

        free(full_command);
    } else {
        waitpid(child_pid, &status, 0);
    }
}

/**
 * execute_commands - Execute multiple commands separated by ';'
 * @input: The input string containing multiple commands
 */
void execute_commands(char *input) {
    char *token = strtok(input, ";");

    while (token != NULL) {
        execute_command(token);
        token = strtok(NULL, ";");
    }
}
