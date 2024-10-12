#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H




#include "Order.h"
#include <string>

// Order Implementation
// The OrderQueue class stores a collection of Orders, each containing the customer name and an ItemList
// Orders are connected in a singly-linked fashion

// Order Queue
class OrderQueue {
public:
    // destructor reallocates memory
    ~OrderQueue();

    // orderCount getter
    int getOrderCount() const;
    // addOrder enqueues Order at the end and increments orderCount
    // if express parameter is true, enqueue at the beginning
    void addOrder(std::string customerName, bool express = false);
    // processOrder dequeues Order at the beginning and decrements orderCount
    void processOrder();
    // displayOrders shows details of every order in the Queue
    void displayOrders();
private:
    Order* firstPtr{nullptr};
    Order* lastPtr{nullptr};
    int orderCount{0}; // pending orders count is stored here and retrieved via its getter
};



#endif //ORDERQUEUE_H
