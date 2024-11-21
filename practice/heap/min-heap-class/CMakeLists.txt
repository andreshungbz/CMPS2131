cmake_minimum_required(VERSION 3.29)
project(min_heap_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(min_heap_class main.cpp
        MinHeapPQ.cpp
        MinHeapPQ.h)
