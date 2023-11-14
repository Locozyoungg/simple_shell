#include "shell.h"
#include <stdlib.h>

void handle_exit(char *argument) {
    if (argument != NULL) {
        int exit_status = atoi(argument);
        exit(exit_status);
    } else {
        exit(0);
    }
}
