cmake_minimum_required(VERSION 3.29)
project(19_exercises)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(19_exercises
        include/ListNode.h
        include/List.h
        include/Stack.h
        src/19-11-palindrome-test-stack.cpp
        include/TreeNode.h
        include/Tree.h)
