cmake_minimum_required(VERSION 3.14)
project(get_next_line)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(libft)

add_executable(get_next_line
        get_next_line.h
        gnl1.c
        text.txt)
