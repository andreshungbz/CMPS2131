cmake_minimum_required(VERSION 3.29)
project(food_order_management_system_refactored)

set(CMAKE_CXX_STANDARD 20)

include_directories(src headers)

add_executable(food_order_management_system_refactored main.cpp
        src/Item.cpp
        headers/Item.h
        src/ItemQueue.cpp
        headers/ItemQueue.h
        src/Order.cpp
        headers/Order.h
        src/OrderQueue.cpp
        headers/OrderQueue.h
        src/FoodOrderManagementSystem.cpp
        headers/FoodOrderManagementSystem.h)
