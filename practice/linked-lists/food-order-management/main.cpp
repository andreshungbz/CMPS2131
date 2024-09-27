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

    void display(int orderNumber, int itemNumber) const {
        std::cout << "\tItem " << orderNumber << '.' << itemNumber << ") " << itemName << " (quantity: "
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
        Item* itemPtr{new Item(itemName, itemQuantity)};
        ++itemCount;

        if (itemQueueHead == nullptr) {
            itemQueueHead = itemPtr;
            return;
        }

        Item* currentPtr{itemQueueHead};
        while (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = itemPtr;
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
    void displayItems(int number) const {
        if (itemQueueHead == nullptr) {
            std::cout << "ItemQueue is empty.\n";
            return;
        }

        int counter{1};

        Item* currentPtr{itemQueueHead};
        while (currentPtr != nullptr) {
            currentPtr->display(number, counter++);
            currentPtr = currentPtr->next;
        }
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

    void display(int number) const {
        std::cout << "Order " << number << ") " << customerName << '\n';
        itemsList.displayItems(number);
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

    // addOrder enqueues Order at the end and increments orderCount
    void addOrder(std::string customerName, bool express = false) {
        Order* orderPtr{new Order(customerName)};
        ++orderCount;

        // add items to order
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

        if (orderQueueHead == nullptr) {
            orderQueueHead = orderPtr;
            return;
        }

        // express orders become the new first order in the queue
        if (express) {
            orderPtr->next = orderQueueHead;
            orderQueueHead = orderPtr;
            return;
        }

        Order* currentPtr{orderQueueHead};
        while (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = orderPtr;
    }

    // processOrder dequeues Order at the beginning and decrements orderCount
    void processOrder() {
        if (orderQueueHead == nullptr) {
            std::cout << "The order queue is empty.\n";
            return;
        }

        // display order details before deleting
        std::cout << "-- Next Order --\n";
        orderQueueHead->display(0);
        std::cout << '\n';

        char response{};
        std::cout << "Process this Order? (y/n): ";
        std::cin >> response;

        if (response == 'y' || response == 'Y') {
            Order* tempPtr{orderQueueHead};
            orderQueueHead = orderQueueHead->next;
            delete tempPtr;

            --orderCount;
            std::cout << "Order has been processed.\n";
        }
    }

    // displayOrders shows details of every order in the Queue
    void displayOrders() {
        if (orderQueueHead == nullptr) {
            std::cout << "The order queue is empty.\n";
            return;
        }

        int counter{1};

        Order* currentPtr{orderQueueHead};
        while (currentPtr != nullptr) {
            currentPtr->display(counter++);
            currentPtr = currentPtr->next;
            std::cout << '\n';
        }
    }
private:
    Order* orderQueueHead{nullptr};
    int orderCount{0};
};

class FoodOrderManagementSystem {
public:
    explicit FoodOrderManagementSystem(std::string name) : systemName(name) {}

    void placeOrder() {
        std::cout << "\n-- Place Order --\n";

        std::string customerName{};
        std::cout << "Enter customer name: ";
        std::getline(std::cin >> std::ws, customerName);

        system.addOrder(customerName);
        std::cout << '\n';
    }

    void placeExpressOrder() {
        std::cout << "\n-- Place Express Order --\n";

        std::string customerName{};
        std::cout << "Enter customer name: ";
        std::getline(std::cin >> std::ws, customerName);

        system.addOrder(customerName, true);
        std::cout << '\n';
    }

    void processNextOrder() {
        std::cout << "\n-- Process Next Order --\n\n";
        system.processOrder();
        std::cout << '\n';
    }

    void pendingOrders() {
        std::cout << "\n-- Pending Orders --\n\n";
        system.displayOrders();
    }

    void pendingOrdersCount() {
        std::cout << "\n-- Pending Orders Count --\n";
        std::cout << "There are " << system.getOrderCount() << " pending orders in "
            << systemName << '\n';
        std::cout << '\n';
    }

    void printMenu() {
        std::cout << "Food Order Management System Options\n";

        std::cout << "1) Place Order\n";
        std::cout << "2) Place Express Order\n";
        std::cout << "3) Process Next Order\n";
        std::cout << "4) Pending Orders\n";
        std::cout << "5) Pending Orders Count\n";
        std::cout << "6) Stop Program\n";

        std::cout << '\n';
    }

    void driverProgram() {
        std::cout << "-- Welcome to the " << systemName << " Food Order Management System! --\n\n";

        int response{0};
        while (true) {
            printMenu();
            std::cout << "Enter option number (1-6): ";
            std::cin >> response;

            switch(response) {
            case 1:
                placeOrder();
                break;
            case 2:
                placeExpressOrder();
                break;
            case 3:
                processNextOrder();
                break;
            case 4:
                pendingOrders();
                break;
            case 5:
                pendingOrdersCount();
                break;
            case 6:
                std::cout << "Exiting program...\n";
                return;
            default:
                std::cout << "Invalid option. Try Again.\n\n";
            }
        }
    }
private:
    std::string systemName{};
    OrderQueue system{};
};

int main() {
    FoodOrderManagementSystem hoosieBurgers{"Hoosie Burgers"};
    hoosieBurgers.driverProgram();

    return 0;
}
