# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(Main src/main.c src/tree.c src/tree.h)

add_executable(Test test/test.c src/tree.c src/tree.h)