//
// Created by root on 11/4/26.
//

#include <stdatomic.h>
#include "handlers.h"

extern sem_t sem_SIG_LOG;
extern volatile sig_atomic_t recieved_data_SIGRTMIN;


void handler_sigrtmin(int signo, siginfo_t * info, void * other){

    sem_post(&sem_SIG_LOG);
    recieved_data_SIGRTMIN = signo;


}
