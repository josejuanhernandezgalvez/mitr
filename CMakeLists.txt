cmake_minimum_required(VERSION 3.17)
project(mitr C)

set(CMAKE_C_STANDARD 99)

add_executable(mitr main.c filter.c filter.h processor.c processor.h utils.c utils.h errors.c errors.h)