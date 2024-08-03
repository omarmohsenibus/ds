cmake_minimum_required(VERSION 3.28)
project(ds C)

set(CMAKE_C_STANDARD 11)

add_executable(ds src/main.c
        src/stack.c
        include/stack.h)
