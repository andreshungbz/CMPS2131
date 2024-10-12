#include "Item.h"
#include <iostream>

// displays item in formated fashion
void Item::display(int orderNumber, int itemNumber) const {
    std::cout << "\tItem " << orderNumber << '.' << itemNumber << ") " << itemName << " (quantity: "
        << itemQuantity << ")\n";
}