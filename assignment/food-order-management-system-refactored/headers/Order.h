#ifndef ORDER_H
#define ORDER_H



#include "ItemQueue.h"
#include <string>

// Order Node
class Order {
public:
    // constructor
    explicit Order(std::string& name) : customerName(name) {}

    // displays order and items in formatted fashion
    void display(int number) const;

    // data members
    // these are public for convenience, but if made private, friend class is applied to OrderQueue
    // friend class OrderQueue;
    std::string customerName{};
    ItemQueue itemsList{};
    bool express{false};
    Order* next{nullptr}; // link to next order
};



#endif //ORDER_H
