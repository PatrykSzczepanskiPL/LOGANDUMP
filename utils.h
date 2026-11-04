//
// Created by root on 11/4/26.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H
#define SIGPROGLOG (SIGRTMIN)
#define SIGPROGDUMP (SIGRTMIN + 1)

typedef enum IS_LOGGIN {
    FALSE = 0,
    TRUE = 1
}IS_LOGGIN;

typedef enum LOGGING_DETAIL{
    MIN,
    STD,
    MAX
}LOGGING_DETAIL;


typedef struct server_data_t{
    FILE * log_file_ptr;
    volatile int clients_served;
    volatile int current_clients;
    volatile int memory_occupied;
    volatile IS_LOGGIN is_logging;
    volatile LOGGING_DETAIL logging_detail;
}server_data_t;






#endif //SERVER_UTILS_H
