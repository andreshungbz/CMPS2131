cmake_minimum_required(VERSION 3.29)
project(19_06_tree)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(19_06_tree src/main.cpp
        include/TreeNode.h
        include/Tree.h)
