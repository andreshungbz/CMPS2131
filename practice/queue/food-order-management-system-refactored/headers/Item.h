#ifndef ITEM_H
#define ITEM_H




#include <string>

// Item Node
class Item {
public:
    // constructor
    Item(std::string& name, int itemQuantity)
        : itemName(name), itemQuantity(itemQuantity) {}

    // displays item in formated fashion
    void display(int orderNumber, int itemNumber) const;

    // data members
    // these are public for convenience, but if made private, friend class is applied to ItemQueue
    // friend class ItemQueue;
    std::string itemName{};
    int itemQuantity{};
    Item* next{nullptr}; // link to next item
};



#endif //ITEM_H
