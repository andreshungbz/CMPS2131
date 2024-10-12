#include "FoodOrderManagementSystem.h"
#include <iostream>
#include <limits>

// Question 1.1 - Create an order with customer name and variable number of items
void FoodOrderManagementSystem::placeOrder() {
    std::cout << "\n-- Place Order --\n";

    // prompt for customer name
    std::string customerName{};
    std::cout << "Enter customer name: ";
    std::getline(std::cin >> std::ws, customerName);

    // add order
    system.addOrder(customerName);

    std::cout << '\n';
}

// Question 2 - Create an express order with higher priority
// Assumption: every new express order is placed after every other express order
void FoodOrderManagementSystem::placeExpressOrder() {
    std::cout << "\n-- Place Express Order --\n";

    // prompt for customer name
    std::string customerName{};
    std::cout << "Enter customer name: ";
    std::getline(std::cin >> std::ws, customerName);

    // add express order
    system.addOrder(customerName, true);

    std::cout << '\n';
}

// Question 1.2 - Display the next order to be processed and prompts to remove it from the queue
void FoodOrderManagementSystem::processNextOrder() {
    std::cout << "\n-- Process Next Order --\n\n";
    system.processOrder();
    std::cout << '\n';
}

// Question 1.3 - Display the pending orders, with customer name and items in each order
void FoodOrderManagementSystem::pendingOrders() {
    std::cout << "\n-- Pending Orders --\n\n";
    system.displayOrders();
}

// Question 1.4 - Display the number of pending orders in the system
void FoodOrderManagementSystem::pendingOrdersCount() {
    std::cout << "\n-- Pending Orders Count --\n";
    std::cout << "There are " << system.getOrderCount() << " pending order(s) in "
        << systemName << '\n';
    std::cout << '\n';
}

// Menu-driven driver program that prompts user continually until program exit
void FoodOrderManagementSystem::driverProgram() {
    std::cout << "-- Welcome to the " << systemName << " Food Order Management System! --\n";

    int response{0};
    while (true) {
        printMenu();
        std::cout << "Enter option number (1-6): ";
        std::cin >> response;

        // add basic input validation
        // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // clear input buffer
        std::cin.ignore();

        // Execute corresponding member function
        switch(response) {
        case 1:
            placeOrder();
            pause();
            break;
        case 2:
            placeExpressOrder();
            pause();
            break;
        case 3:
            processNextOrder();
            pause();
            break;
        case 4:
            pendingOrders();
            pause();
            break;
        case 5:
            pendingOrdersCount();
            pause();
            break;
        case 6: // Question 1.5 - This option exits the program
            std::cout << "Exiting program...\n";
            return;
        default:
            std::cout << "Invalid option. Try Again.\n\n";
        }
    }
}

// utility function for printing the system options menu
void FoodOrderManagementSystem::printMenu() {
    std::cout << "\n-- Food Order Management System Options --\n";

    std::cout << "1) Place Order\n";
    std::cout << "2) Place Express Order\n";
    std::cout << "3) Process Next Order\n";
    std::cout << "4) Pending Orders\n";
    std::cout << "5) Pending Orders Count\n";
    std::cout << "6) Stop Program\n";

    std::cout << '\n';
}

// utility function for pausing on Windows systems only
void FoodOrderManagementSystem::pause() {
#if defined(_WIN32)
    std::system("pause");
#endif
}