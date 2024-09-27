#include <iostream>
#include <string>

// Item Implementation
// The ItemQueue class stores a collection of Items, each containing an item name and its quantity.
// Items are connected in a singly-linked fashion.
// Assumption: items are processed (removed) FIFO.

// Item Node
class Item {
public:
    Item(std::string& name, int itemQuantity)
        : itemName(name), itemQuantity(itemQuantity) {}

    void display() const {
        int counter{1};

        std::cout << '\t' << counter++ << ") " << itemName << " (quantity: "
            << itemQuantity << ")\n";
    }

    std::string itemName{};
    int itemQuantity{};
    Item* next{nullptr};
};

// Item Queue
class ItemQueue {
public:
    // destructor reallocates memory
    ~ItemQueue() {
        while (itemQueueHead != nullptr) {
            Item* tempPtr{itemQueueHead};
            itemQueueHead = itemQueueHead->next;
            delete tempPtr;
        }
    }

    // itemCount getter
    int getItemCount() const {
        return itemCount;
    }

    // addItem enqueues Item at the end and increments itemCount
    void addItem(std::string itemName, int itemQuantity) {
        Item* newPtr{new Item(itemName, itemQuantity)};
        ++itemCount;

        if (itemQueueHead == nullptr) {
            itemQueueHead = newPtr;
            return;
        }

        Item* currentPtr{itemQueueHead};
        while (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = newPtr;
    }

    // processItem dequeues Item at the beginning and decrements itemCount
    void processItem() {
        if (itemQueueHead == nullptr) {
            std::cout << "ItemQueue is empty.\n";
            return;
        }

        Item* tempPtr{itemQueueHead};
        itemQueueHead = itemQueueHead->next;
        delete tempPtr;
        --itemCount;
    }

    // displayItems shows details of every item in the Queue
    void displayItems() const {
        if (itemQueueHead == nullptr) {
            std::cout << "ItemQueue is empty.\n";
            return;
        }
        Item* currentPtr{itemQueueHead};
        while (currentPtr != nullptr) {
            currentPtr->display();
            currentPtr = currentPtr->next;
        }

        std::cout << '\n';
    }
private:
    Item* itemQueueHead{nullptr};
    int itemCount{0};
};

// Order Implementation
// The OrderQueue class stores a collection of Orders, each containing the customer name and an ItemList
// Orders are connected in a singly-linked fashion

// Order Node
class Order {
public:
    explicit Order(std::string& name) : customerName(name) {}

    void display() const {
        int counter{1};

        std::cout << counter++ << ") " << customerName << '\n';
        itemsList.displayItems();
        std::cout << '\n';
    }

    std::string customerName{};
    ItemQueue itemsList{};
    Order* next{nullptr};
};

// Order Queue
class OrderQueue {
public:
    // destructor reallocates memory
    ~OrderQueue() {
        while (orderQueueHead != nullptr) {
            Order* tempPtr{orderQueueHead};
            orderQueueHead = orderQueueHead->next;
            delete tempPtr;
        }
    }

    // orderCount getter
    int getOrderCount() const {
        return orderCount;
    }

    // TODO: change this function to prompt user
    // addOrder enqueues Order at the end and increments orderCount
    void addOrder(std::string customerName) {
        // TODO: get customer name from user

        Order* newPtr{new Order(customerName)};
        ++orderCount;

        // TODO: prompt user for items and quantities

        if (orderQueueHead == nullptr) {
            orderQueueHead = newPtr;
            return;
        }

        Order* currentPtr{orderQueueHead};
        while (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = newPtr;
    }

    // TODO: have this display the order before deleting it
    // processOrder dequeues Order at the beginning and decrements orderCount
    void processOrder() {
        if (orderQueueHead == nullptr) {
            std::cout << "OrderQueue is empty.\n";
            return;
        }

        Order* tempPtr{orderQueueHead};
        orderQueueHead = orderQueueHead->next;
        delete tempPtr;
        --orderCount;
    }

    // displayOrders shows details of every order in the Queue
    void displayOrders() {
        if (orderQueueHead == nullptr) {
            std::cout << "OrderQueue is empty.\n";
            return;
        }

        Order* currentPtr{orderQueueHead};
        while (currentPtr != nullptr) {
            currentPtr->display();
            currentPtr = currentPtr->next;
        }

        std::cout << '\n';
    }
private:
    Order* orderQueueHead{nullptr};
    int orderCount{0};
};

class FoodManagementSystem {
public:
    Order* firstOrder{nullptr};
    int pendingOrdersCount{0};
};

int main() {
    ItemQueue queue{};
    queue.displayItems();
    queue.addItem("apple", 4);
    queue.addItem("orange", 2);
    queue.addItem("milk", 1);
    queue.processItem();
    queue.processItem();
    queue.displayItems();

    return 0;
}
