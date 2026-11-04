#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>

#include "threads.h"
#include "handlers.h"
#include "utils.h"
#include "logger.h"

sem_t sem_SIG_LOG;
sem_t sem_SIG_DUMP;
volatile sig_atomic_t recieved_data_SIGRTMIN;

volatile server_data_t serverData = {};

int main() {
    srand(42);
    FILE * fp_log = fopen("log.txt", "a+");
    serverData.log_file_ptr = fp_log;
    serverData.is_logging = TRUE;
    serverData.logging_detail = MAX;

    printf("Server PID: %d\n", getpid());


    sigset_t set;
    struct sigaction act;
    pthread_t tid_SIGRTMIN;
    pthread_t tid_LOGGER;


    sem_init(&sem_SIG_LOG, 0, 0);

    sigfillset(&set);
    pthread_sigmask(SIG_SETMASK,&set, NULL);

    act.sa_sigaction = handler_sigrtmin;
    act.sa_mask = set;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGRTMIN, &act, NULL);
    pthread_create(&tid_SIGRTMIN, NULL, signal_thread, NULL);
    pthread_create(&tid_LOGGER,NULL, log_thread, (void *)&serverData);



    while(1){
        printf("running\n");
        serverData.clients_served +=1;
        serverData.current_clients = rand() % 10;
        serverData.memory_occupied = (rand() % (1000 - 450)) + 450;
        sleep(2);
    }


    fclose(fp_log);
    pthread_join(tid_LOGGER, NULL);
    pthread_join(tid_SIGRTMIN, NULL);
    sem_destroy(&sem_SIG_LOG);
    return 0;
}

