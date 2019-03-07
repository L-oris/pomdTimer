#include "./getcommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readln(char str[]) {
    int i = 0;
    char current_char;
    while (1) {
        current_char = getchar();
        if ((current_char == '\n') || (current_char == EOF)) {
            break;
        }
        if (i < MAX_STRING_LEN - 1) {
            str[i] = current_char;
            i++;
        }
    }
    str[i] = '\0';
    return i;
}

char* getcommand() {
    char* command = malloc(MAX_STRING_LEN * sizeof(char));
    readln(command);
    return command;
}