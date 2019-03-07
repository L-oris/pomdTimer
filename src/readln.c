#include "readln.h"
#include <stdio.h>
#include <string.h>

char getcommand() {
    char command[MAXSTRLEN];
    int commandlen;
    char c;

    commandlen = readln(command);
    if (commandlen != 1) {
        c = 'x';
    } else {
        c = command[0];
    }
    return c;
}

int readln(char s[]) {
    char ch;
    int i;
    int chars_remain;
    i = 0;
    chars_remain = 1;
    while (chars_remain) {
        ch = getchar();
        if ((ch == '\n') || (ch == EOF)) {
            chars_remain = 0;
        } else if (i < MAXSTRLEN - 1) {
            s[i] = ch;
            i++;
        }
    }
    s[i] = '\0';
    return i;
}