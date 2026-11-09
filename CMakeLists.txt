cmake_minimum_required(VERSION 3.20)
project(server C)

set(CMAKE_C_STANDARD 11)

add_executable(server main.c logger.c logger.h)
target_link_libraries(server -pthread)