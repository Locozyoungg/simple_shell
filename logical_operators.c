#include "shell.h"

#include <string.h>

int execute_logical_operators(char *input) {
    char **commands = custom_tokenize(input, ';', MAX_COMMANDS);
    int result = 0;

    for (size_t i = 0; commands[i] != NULL; ++i) {
        char *command = commands[i];

        if (strlen(command) > 0) {
            result = execute_commands(command);

            if (result != 0)
                break;
        }
    }

    free(commands);

    return result;
}
