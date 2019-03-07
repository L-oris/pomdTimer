#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define TIMER_COUNTDOWN 5

int main() {
    time_t initial_time = time(NULL);
    while (1) {
        if (time(NULL) - initial_time > TIMER_COUNTDOWN) {
            printf("done\n");
            return 0;
        }
    }
}
