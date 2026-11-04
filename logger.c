//
// Created by root on 11/4/26.
//

#include "logger.h"


void * log_thread(void * input){
    server_data_t * server_data_ptr = (server_data_t *)input;


    while(server_data_ptr->is_logging == TRUE){
        time_t now = time(NULL);
        struct tm *t = localtime(&now);



        switch (server_data_ptr->logging_detail) {
            case MIN:{
                fprintf(server_data_ptr->log_file_ptr,"[MIN] | [%d:%d:%d] | Clients served: %d \n", t->tm_hour,t->tm_min,t->tm_sec, server_data_ptr->clients_served);
                break;
            }
            case STD:{
                fprintf(server_data_ptr->log_file_ptr,"[STD] | [%d:%d:%d] | Clients served: %d  | Current clients: %d\n",t->tm_hour,t->tm_min,t->tm_sec, server_data_ptr->clients_served,server_data_ptr->current_clients);
                break;
            }
            case MAX:{
                fprintf(server_data_ptr->log_file_ptr,"[MAX] | [%d:%d:%d] | Clients served: %d  | Current clients: %d | Memory Occupied: %d\n",t->tm_hour,t->tm_min,t->tm_sec, server_data_ptr->clients_served,server_data_ptr->current_clients ,server_data_ptr->memory_occupied);
                break;
            }
        }
        fflush(server_data_ptr->log_file_ptr);

        sleep(5);
    }



    return NULL;
}

