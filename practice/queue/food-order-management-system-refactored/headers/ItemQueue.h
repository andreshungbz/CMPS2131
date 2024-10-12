#ifndef ITEMQUEUE_H
#define ITEMQUEUE_H



#include "Item.h"

// Item Implementation
// The ItemQueue class stores a collection of Items, each containing an item name and its quantity.
// Items are connected in a singly-linked fashion.
// Assumption: items are processed (removed) FIFO.

// Item Queue
class ItemQueue {
public:
    // destructor reallocates memory
    ~ItemQueue();

    // itemCount getter
    int getItemCount() const;
    // addItem enqueues Item at the end and increments itemCount
    void addItem(std::string itemName, int itemQuantity);
    // processItem dequeues Item at the beginning and decrements itemCount
    void processItem();
    // displayItems shows details of every item in the Queue
    void displayItems(int number) const;
private:
    Item* firstPtr{nullptr};
    Item* lastPtr{nullptr};
    int itemCount{0};
};



#endif //ITEMQUEUE_H
