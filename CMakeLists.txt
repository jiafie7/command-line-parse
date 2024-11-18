cmake_minimum_required(VERSION 3.19)

project(command-line-parse)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g -O2 -Wall -Werror)

include_directories(./)

file(GLOB_RECURSE SOURCES "./utility/*.cpp")

add_executable(main ${SOURCES} main.cpp)
