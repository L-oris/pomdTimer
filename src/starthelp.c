#include "./starthelp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void help() {
    printf("\nCommands:\n");
    printf("* h: provides help\n");
    printf("* s: starts the timer\n");
    printf("* q: exits the program\n");
}