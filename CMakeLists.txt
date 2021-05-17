cmake_minimum_required(VERSION 3.17)
project(test_projet C)

set(CMAKE_C_STANDARD 99)

add_executable(test_projet main.c PuissanceN.c PuissanceN.h)