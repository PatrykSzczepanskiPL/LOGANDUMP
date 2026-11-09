#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "logger.h"
volatile int counter = 0;

void moj_dump(FILE *f) {
    fprintf(f, "Stan serwera: OK\nLiczba klientow: %d\n", counter);
}

int main(void) {
    printf("Pid aplikacji: %d\n", getpid());
    logger_init("app.log", "moj_serwer", moj_dump);
    scanf("%d", (int*)NULL);
    printf("start\n");
    while(counter <= 20){
        printf("counter %d\n", counter);
        logger_log(LOG_LEVEL_MAX, "COUNTER %d", counter);
        logger_log(LOG_LEVEL_MIN, "TEST MIN!");
        logger_log(LOG_LEVEL_STANDARD, "TEST STD!");
        logger_log(LOG_LEVEL_MAX, "TEST MAX!");
        counter++;
        usleep(500000);
    }

    logger_destroy();
    return 0;
}