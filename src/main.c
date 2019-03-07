#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./getcommand.h"

#define TIMER_COUNTDOWN 5

void help() {
    printf("\nCommands:\n");
    printf("* h: provides help\n");
    printf("* s: starts the timer\n");
    printf("* q: exits the program\n");
}

int start() {
    time_t initial_time = time(NULL);
    time_t final_time = initial_time + TIMER_COUNTDOWN;
    int time_gap = TIMER_COUNTDOWN;

    while (1) {
        int updated_time_gap = final_time - time(NULL);

        if (updated_time_gap <= 0) {
            printf("\r🕐  - Session ended\n");
            fflush(stdout);
            return 0;
        }

        if (updated_time_gap != time_gap) {
            time_gap = updated_time_gap;
            printf("\r🕐  - %d..", time_gap);
            fflush(stdout);
        }
    }
}

int main(int argc, char** argv) {
    int keepgoing = 1;
    while (keepgoing) {
        printf("\n🍅  ");

        char* command = getcommand();
        if (strcmp(command, "start") == 0) {
            start();
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
