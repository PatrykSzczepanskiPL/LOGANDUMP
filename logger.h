//
// Created by root on 11/4/26.
//

#ifndef SERVER_LOGGER_H
#define SERVER_LOGGER_H
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <signal.h>
#include <stdatomic.h>
#include <unistd.h>
#include <time.h>

void * log_thread(void *);

#endif //SERVER_LOGGER_H
