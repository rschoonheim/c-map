cmake_minimum_required(VERSION 3.29)
project(c_map C)

set(CMAKE_C_STANDARD 23)

add_library(c_hash_map STATIC hash_map.c)

add_executable(main main.c)

target_link_libraries(main c_hash_map)
