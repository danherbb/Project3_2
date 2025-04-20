cmake_minimum_required(VERSION 3.26)
project(Project3_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project3_2 src/main.cpp
        src/lzw.cpp
        src/lzw.h
        src/huffman.cpp
        src/huffman.h)
