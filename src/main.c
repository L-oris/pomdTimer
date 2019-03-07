#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "readln.h"

#define TIMER_COUNTDOWN 5

char getcommand() {
    char command[MAX_STRING_LEN];
    int commandlen = readln(command);
    if (commandlen != 1) {
        return 'x';
    }
    return command[0];
}

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

    printf("\n");
    while (1) {
        int updated_time_gap = final_time - time(NULL);

        if (updated_time_gap <= 0) {
            //remove line
            fputs("\033[A\033[2K", stdout);
            rewind(stdout);
            printf("🕐  - Session ended\n");
            return 0;
        }

        if (updated_time_gap != time_gap) {
            time_gap = updated_time_gap;
            //remove line
            fputs("\033[A\033[2K", stdout);
            rewind(stdout);
            printf("🕐  %d..\n", time_gap);
        }
    }
}

int main(int argc, char** argv) {
    int keepgoing = 1;
    while (keepgoing) {
        printf("\n🍅  ");
        switch (getcommand()) {
            case 'h':
                help();
                break;
            case 's':
                start();
                break;
            case 'q':
                printf("Ending...\n");
                keepgoing = 0;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
}
