# Template for CMakeLists.txt

# set the minimum required version of CMake
cmake_minimum_required(VERSION 3.29)

# set the project name
project(19_03_05_linked_list)

# set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# add the include directory to the include path for header files
include_directories(include)

# add the executable target name and sources
add_executable(19_03_05_linked_list src/main.cpp
)
