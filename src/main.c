#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./getcommand.h"
#include "./starthelp.h"

int main(int argc, char** argv) {
    int keepgoing = 1;
    while (keepgoing) {
        printf("\n🍅  ");

        char* command = getcommand();
        if (strncmp(command, "start", 5) == 0) {
            int time_gap = atoi(command + 6);
            start(time_gap);
            continue;
        }

        if (strcmp(command, "help") == 0) {
            help();
            continue;
        }

        if (strcmp(command, "quit") == 0) {
            printf("Ending...\n");
            keepgoing = 0;
            break;
        }

        printf("Invalid command\n");
        free(command);
    }
}
