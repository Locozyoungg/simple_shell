#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line;

    while (1) {
        printf(":) ");
        line = custom_getline();

        if (line == NULL) {
            printf("\n");
            break;
        }

        printf("You entered: %s\n", line);
        free(line);
    }

    return 0;
}
