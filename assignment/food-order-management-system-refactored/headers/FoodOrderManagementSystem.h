#ifndef FOODORDERMANAGEMENTSYSTEM_H
#define FOODORDERMANAGEMENTSYSTEM_H



#include "OrderQueue.h"

// FoodOrderManagementSystem Implementation
// The FoodOrderManagementSystem Class utilizes the OrderQueue Class and contains the driver program

class FoodOrderManagementSystem {
public:
    // constructor
    explicit FoodOrderManagementSystem(std::string name) : systemName(name) {}

    // Question 1.1 - Create an order with customer name and variable number of items
    void placeOrder();
    // Question 2 - Create an express order with higher priority
    // Assumption: every new express order is placed after every other express order
    void placeExpressOrder();
    // Question 1.2 - Display the next order to be processed and prompts to remove it from the queue
    void processNextOrder();
    // Question 1.3 - Display the pending orders, with customer name and items in each order
    void pendingOrders();
    // Question 1.4 - Display the number of pending orders in the system
    void pendingOrdersCount();
    // Menu-driven driver program that prompts user continually until program exit
    void driverProgram();
private:
    std::string systemName{};
    OrderQueue system{};

    // utility function for printing the system options menu
    static void printMenu();
    // utility function for pausing on Windows systems only
    void pause();
};



#endif //FOODORDERMANAGEMENTSYSTEM_H
