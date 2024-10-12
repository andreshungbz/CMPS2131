#include "ItemQueue.h"
#include <iostream>

// destructor reallocates memory
ItemQueue::~ItemQueue() {
    while (firstPtr != nullptr) {
        Item* tempPtr{firstPtr};
        firstPtr = firstPtr->next;
        delete tempPtr;
    }
}

// itemCount getter
int ItemQueue::getItemCount() const {
    return itemCount;
}

// addItem enqueues Item at the end and increments itemCount
void ItemQueue::addItem(std::string itemName, int itemQuantity) {
    Item* itemPtr{new Item(itemName, itemQuantity)};
    ++itemCount;

    if (firstPtr == nullptr && lastPtr == nullptr) {
        firstPtr = lastPtr = itemPtr;
        return;
    }

    lastPtr->next = itemPtr;
    lastPtr = itemPtr;
}

// processItem dequeues Item at the beginning and decrements itemCount
void ItemQueue::processItem() {
    if (firstPtr == nullptr || lastPtr == nullptr) {
        std::cout << "ItemQueue is empty.\n";
        return;
    }

    Item* tempPtr{firstPtr};

    if (firstPtr == lastPtr) {
        delete tempPtr;
        firstPtr = lastPtr = nullptr;
        return;
    }

    firstPtr = firstPtr->next;
    delete tempPtr;
    --itemCount;
}

// displayItems shows details of every item in the Queue
void ItemQueue::displayItems(int number) const {
    if (firstPtr == nullptr) {
        std::cout << "ItemQueue is empty.\n";
        return;
    }

    int counter{1};

    Item* currentPtr{firstPtr};
    while (currentPtr != nullptr) {
        currentPtr->display(number, counter++);
        currentPtr = currentPtr->next;
    }
}