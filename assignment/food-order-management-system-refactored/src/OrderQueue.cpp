#include "OrderQueue.h"
#include <iostream>

// destructor reallocates memory
OrderQueue::~OrderQueue() {
    while (firstPtr != nullptr) {
        Order* tempPtr{firstPtr};
        firstPtr = firstPtr->next;
        delete tempPtr;
    }
}

// orderCount getter
int OrderQueue::getOrderCount() const {
    return orderCount;
}

// addOrder enqueues Order at the end and increments orderCount
    // if express parameter is true, enqueue at the beginning
    void OrderQueue::addOrder(std::string customerName, bool express) {
        Order* orderPtr{new Order(customerName)};
        ++orderCount;

        // prompt for items to add to the order
        char continuePrompt{};
        do {
            // add at least one item to Order
            std::string itemName{};
            int itemQuantity{};
            std::cout << "Enter item name: ";
            std::getline(std::cin >> std::ws, itemName);
            std::cout << "Enter quantity of " << itemName << ": ";
            std::cin >> itemQuantity;

            orderPtr->itemsList.addItem(itemName, itemQuantity);

            std::cout << "\nAdd another item? (y/n): ";
            std::cin >> continuePrompt;
        } while (continuePrompt == 'y' || continuePrompt == 'Y');

        // feedback
        std::cout << "Order has been added to system!\n";

        if (express) {
            // set Order as express
            orderPtr->express = true;

            if (firstPtr == nullptr) {
                firstPtr = lastPtr = orderPtr;
                return;
            }

            // express order becomes the new first order in the queue if no other express orders exist
            if (!firstPtr->express) {
                orderPtr->next = firstPtr;
                firstPtr = orderPtr;
                return;
            }

            Order* currentPtr{firstPtr};
            while (currentPtr->next != nullptr && currentPtr->next->express) {
                currentPtr = currentPtr->next;
            }

            orderPtr->next = currentPtr->next;
            currentPtr->next = orderPtr;

            // if the express order is the last order, set lastPtr
            if (orderPtr->next == nullptr) {
                lastPtr = orderPtr;
            }
        } else {
            if (firstPtr == nullptr && lastPtr == nullptr) {
                firstPtr = lastPtr = orderPtr;
                return;
            }

            lastPtr->next = orderPtr;
            lastPtr = orderPtr;
        }
    }

// processOrder dequeues Order at the beginning and decrements orderCount
void OrderQueue::processOrder() {
    if (firstPtr == nullptr && lastPtr == nullptr) {
        std::cout << "The order queue is empty.\n";
        return;
    }

    // display order details
    std::cout << "-- Next Order --\n";
    firstPtr->display(0); // 0 symbolizes the most immediate order
    std::cout << '\n';

    char response{};
    std::cout << "Process this Order? (y/n): ";
    std::cin >> response;

    if (response == 'y' || response == 'Y') {
        Order* tempPtr{firstPtr};

        if (firstPtr == lastPtr) {
            delete tempPtr;
            firstPtr = lastPtr = nullptr;
            --orderCount;

            std::cout << "Order has been processed.\n";

            return;
        }

        firstPtr = firstPtr->next;
        delete tempPtr;
        --orderCount;

        std::cout << "Order has been processed.\n";
    }
}

// displayOrders shows details of every order in the Queue
void OrderQueue::displayOrders() {
    if (firstPtr == nullptr) {
        std::cout << "The order queue is empty.\n\n";
        return;
    }

    // this counter is passed progressively into the display functions
    // of Order and Item for formatting
    int counter{1};

    Order* currentPtr{firstPtr};
    while (currentPtr != nullptr) {
        currentPtr->display(counter++);
        currentPtr = currentPtr->next;
        std::cout << '\n';
    }
}