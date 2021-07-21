cmake_minimum_required(VERSION 3.17)
project(donut C)

set(CMAKE_C_STANDARD 11)

add_executable(donut main.c donut_p.c donut_p.h mathme.c mathme.h)