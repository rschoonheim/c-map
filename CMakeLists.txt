cmake_minimum_required(VERSION 3.29)
project(c_map C)

set(CMAKE_C_STANDARD 23)

add_library(c_map STATIC library.c)
