#include "./starthelp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int start(int count_in_seconds) {
    time_t initial_time = time(NULL);
    time_t final_time = initial_time + count_in_seconds;
    int time_gap = count_in_seconds;

    while (1) {
        int updated_time_gap = final_time - time(NULL);

        if (updated_time_gap <= 0) {
            printf("\r🕐  - Session ended\n");
            fflush(stdout);
            return 0;
        }

        if (updated_time_gap != time_gap) {
            time_gap = updated_time_gap;
            printf("\r🕐  - %d seconds", time_gap);
            fflush(stdout);
        }
    }
}

void help() {
    printf("\n Commands:\n\n");
    printf("	help			Provides help\n");
    printf("	start [options]		Starts the timer\n");
    printf("	quit			Quits the program\n");
}