# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled src/main.c src/tree.c src/tree.h test/test.c test/test.h)