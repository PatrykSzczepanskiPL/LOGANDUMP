cmake_minimum_required(VERSION 3.20)
project(server C)

set(CMAKE_C_STANDARD 11)

add_executable(server main.c handlers.c handlers.h threads.c threads.h logger.c logger.h utils.h)
target_link_libraries(server -pthread)