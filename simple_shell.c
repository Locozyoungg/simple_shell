#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
* main - Entry point of the shell
*
* Return: Always 0
*/
int main(void)
{
char input[MAX_INPUT_SIZE];
int status;
char *args[2];
pid_t child_pid;

while (1)
{
printf("#cisfun$ ");
if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
{
printf("\n");
break;
}


input[strcspn(input, "\n")] = 0;


child_pid = fork();

if (child_pid == -1)
{
perror("Fork error");
exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
args[0] = input;
args[1] = NULL;
if (execve(args[0], args, NULL) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}

if (execve(args[0], args, NULL) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else
{

wait(&status);
}
}

return (0);
}

