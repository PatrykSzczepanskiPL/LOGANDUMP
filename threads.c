//
// Created by root on 11/4/26.
//

#include "threads.h"

extern sem_t sem_SIG_LOG;
extern volatile sig_atomic_t recieved_data_SIGRTMIN;


void * signal_thread(void * input){
    (void *) input;
    sigset_t set;
    sigfillset(&set);
    sigdelset(&set, SIGRTMIN);
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    while(1){
        while(sem_wait(&sem_SIG_LOG) != 0){
            printf("sig_rtmin %d ", recieved_data_SIGRTMIN);
        }
    }


    return NULL;
}





