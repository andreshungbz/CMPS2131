TEMPLATE = app
CONFIG += c++17

# project name
TARGET = food_order_management_system_refactored

# include directories
INCLUDEPATH += src headers

# source files
SOURCES += main.cpp \
           src/Item.cpp \
           src/ItemQueue.cpp \
           src/Order.cpp \
           src/OrderQueue.cpp \
           src/FoodOrderManagementSystem.cpp

# header files
HEADERS += headers/Item.h \
           headers/ItemQueue.h \
           headers/Order.h \
           headers/OrderQueue.h \
           headers/FoodOrderManagementSystem.h
