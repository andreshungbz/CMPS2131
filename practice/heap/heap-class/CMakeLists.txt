cmake_minimum_required(VERSION 3.29)
project(heap_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(heap_class main.cpp
        MaxHeap.cpp
        MaxHeap.h)
