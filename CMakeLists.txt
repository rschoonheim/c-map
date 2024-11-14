cmake_minimum_required(VERSION 3.29)
project(c_map C)

set(CMAKE_C_STANDARD 23)

add_library(c_map STATIC cmap.c)

add_executable(main main.c)

target_link_libraries(main c_map)
