#include "Order.h"
#include <iostream>

// displays order and items in formatted fashion
void Order::display(int number) const {
    std::cout << (express ? "Express " : "") << "Order " << number << ") " << customerName << '\n';
    itemsList.displayItems(number);
}