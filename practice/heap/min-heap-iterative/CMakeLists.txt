cmake_minimum_required(VERSION 3.29)
project(min_heap_iterative)

set(CMAKE_CXX_STANDARD 20)

add_executable(min_heap_iterative main.cpp
        MinHeap.cpp
        MinHeap.h)
