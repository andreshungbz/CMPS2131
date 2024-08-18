cmake_minimum_required(VERSION 3.29)
project(19_03_04_05_list_stack_queue)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(19_03_04_05_list_stack_queue
        include/Queue.h
        src/queue-driver.cpp
)
