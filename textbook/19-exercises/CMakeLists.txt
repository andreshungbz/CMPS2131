cmake_minimum_required(VERSION 3.29)
project(19_exercises)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(19_exercises
        include/ListNode.h
        include/List.h
        src/19-08-random-ordered-list.cpp)
