cmake_minimum_required(VERSION 3.30)
project(kjcl C)

set(CMAKE_C_STANDARD 11)

add_library(kjcl STATIC library.c arena.c)
