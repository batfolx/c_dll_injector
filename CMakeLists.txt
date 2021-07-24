cmake_minimum_required(VERSION 3.19)
project(dll_injector C)

set(CMAKE_C_STANDARD 99)

add_executable(dll_injector main.c injector.h injector.c dll/virus.c)