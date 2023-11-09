/*
 * custom_getline.c - Custom getline function for simple shell
 */

#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static size_t buffer_size = 0;
static size_t buffer_pos = 0;

/**
 * custom_getline - Read a line from standard input
 *
 * Return: A pointer to the read line, or NULL on EOF or error.
 */

char *custom_getline(void)
{
    size_t read_size = 0;
    char *line = NULL;
    char *new_line;

    while (1)
    {
        if (buffer_pos >= buffer_size)
        {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (buffer_size == 0)
            {
                if (line != NULL)
                    free(line);
                return NULL;
            }
            buffer_pos = 0;
        }

        while (buffer_pos < buffer_size)
        {
            char c = buffer[buffer_pos++];
            if (c == '\n' || c == '\0')
            {
                if (line != NULL)
                    line[read_size] = '\0';
                return line;
            }

            new_line = (char *)realloc(line, read_size + 2);
            if (new_line == NULL)
            {
                if (line != NULL)
                    free(line);
                return NULL;
            }
            line = new_line;

            line[read_size++] = c;
        }
    }
}

