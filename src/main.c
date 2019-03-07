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

int main(int argc, char** argv) {
    int keepgoing = 1;
    while (keepgoing) {
        printf("\nEnter a command or 'q' to quit.\n");
        switch (getcommand()) {
            case 'q':
                printf("Ending...\n");
                keepgoing = 0;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    // time_t initial_time = time(NULL);
    // while (1) {
    //     if (time(NULL) - initial_time > TIMER_COUNTDOWN) {
    //         printf("done\n");
    //         return 0;
    //     }
    // }
}
