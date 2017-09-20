cmake_minimum_required(VERSION 3.8)
project(reverse)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        file_utils.c
        file_utils.h
        main.c)

add_executable(reverse ${SOURCE_FILES})