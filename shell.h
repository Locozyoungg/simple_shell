#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024

char *custom_getline(void);
void print_environment(void);
int custom_tokenize(char *input, char delim, char *tokens[], int max_tokens);
void handle_exit(char *argument);
int handle_setenv(char *variable, char *value);
int handle_unsetenv(char *variable);
int _strcmp(char *s1, char *s2);
int update_pwd(void);
void handle_cd(char *argument);
void execute_commands(char *input);

#endif /* SHELL_H */
