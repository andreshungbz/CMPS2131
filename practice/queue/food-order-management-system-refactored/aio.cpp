#include <iostream>
#include <limits> // for input validation
#include <string>

// Class Include Structure
// ItemQueue class contains Item instances
// Order class contains one ItemQueue instance
// OrderQueue class contains Order instances
// FoodOrderManagementSystem contains one OrderQueue instance and the driver program

// Item Implementation
// The ItemQueue class stores a collection of Items, each containing an item name and its quantity.
// Items are connected in a singly-linked fashion.
// Assumption: items are processed (removed) FIFO.

// Item Node
class Item {
public:
    // constructor
    Item(std::string& name, int itemQuantity)
        : itemName(name), itemQuantity(itemQuantity) {}

    // displays item in formated fashion
    void display(int orderNumber, int itemNumber) const {
        std::cout << "\tItem " << orderNumber << '.' << itemNumber << ") " << itemName << " (quantity: "
            << itemQuantity << ")\n";
    }

    // data members
    // these are public for convenience, but if made private, friend class is applied to ItemQueue
    // friend class ItemQueue;
    std::string itemName{};
    int itemQuantity{};
    Item* next{nullptr}; // link to next item
};

// Item Queue
class ItemQueue {
public:
    // destructor reallocates memory
    ~ItemQueue() {
        while (firstPtr != nullptr) {
            Item* tempPtr{firstPtr};
            firstPtr = firstPtr->next;
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

        if (firstPtr == nullptr && lastPtr == nullptr) {
            firstPtr = lastPtr = itemPtr;
            return;
        }

        lastPtr->next = itemPtr;
        lastPtr = itemPtr;
    }

    // processItem dequeues Item at the beginning and decrements itemCount
    void processItem() {
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
    void displayItems(int number) const {
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
private:
    Item* firstPtr{nullptr};
    Item* lastPtr{nullptr};
    int itemCount{0};
};

// Order Implementation
// The OrderQueue class stores a collection of Orders, each containing the customer name and an ItemList
// Orders are connected in a singly-linked fashion

// Order Node
class Order {
public:
    // constructor
    explicit Order(std::string& name) : customerName(name) {}

    // displays order and items in formatted fashion
    void display(int number) const {
        std::cout << (express ? "Express " : "") << "Order " << number << ") " << customerName << '\n';
        itemsList.displayItems(number);
    }

    // data members
    // these are public for convenience, but if made private, friend class is applied to OrderQueue
    // friend class OrderQueue;
    std::string customerName{};
    ItemQueue itemsList{};
    bool express{false};
    Order* next{nullptr}; // link to next order
};

// Order Queue
class OrderQueue {
public:
    // destructor reallocates memory
    ~OrderQueue() {
        while (firstPtr != nullptr) {
            Order* tempPtr{firstPtr};
            firstPtr = firstPtr->next;
            delete tempPtr;
        }
    }

    // orderCount getter
    int getOrderCount() const {
        return orderCount;
    }

    // addOrder enqueues Order at the end and increments orderCount
    // if express parameter is true, enqueue at the beginning
    void addOrder(std::string customerName, bool express = false) {
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
    void processOrder() {
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
    void displayOrders() {
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
private:
    Order* firstPtr{nullptr};
    Order* lastPtr{nullptr};
    int orderCount{0}; // pending orders count is stored here and retrieved via its getter
};

// FoodOrderManagementSystem Implementation
// The FoodOrderManagementSystem Class utilizes the OrderQueue Class and contains the driver program

class FoodOrderManagementSystem {
public:
    // constructor
    explicit FoodOrderManagementSystem(std::string name) : systemName(name) {}

    // Question 1.1 - Create an order with customer name and variable number of items
    void placeOrder() {
        std::cout << "\n-- Place Order --\n";

        // prompt for customer name
        std::string customerName{};
        std::cout << "Enter customer name: ";
        std::getline(std::cin >> std::ws, customerName);

        // add order
        system.addOrder(customerName);

        std::cout << '\n';
    }

    // Question 2 - Create an express order with higher priority
    // Assumption: every new express order is placed after every other express order
    void placeExpressOrder() {
        std::cout << "\n-- Place Express Order --\n";

        // prompt for customer name
        std::string customerName{};
        std::cout << "Enter customer name: ";
        std::getline(std::cin >> std::ws, customerName);

        // add express order
        system.addOrder(customerName, true);

        std::cout << '\n';
    }

    // Question 1.2 - Display the next order to be processed and prompts to remove it from the queue
    void processNextOrder() {
        std::cout << "\n-- Process Next Order --\n\n";
        system.processOrder();
        std::cout << '\n';
    }

    // Question 1.3 - Display the pending orders, with customer name and items in each order
    void pendingOrders() {
        std::cout << "\n-- Pending Orders --\n\n";
        system.displayOrders();
    }

    // Question 1.4 - Display the number of pending orders in the system
    void pendingOrdersCount() {
        std::cout << "\n-- Pending Orders Count --\n";
        std::cout << "There are " << system.getOrderCount() << " pending order(s) in "
            << systemName << '\n';
        std::cout << '\n';
    }

    // Menu-driven driver program that prompts user continually until program exit
    void driverProgram() {
        std::cout << "-- Welcome to the " << systemName << " Food Order Management System! --\n";

        int response{0};
        while (true) {
            printMenu();
            std::cout << "Enter option number (1-6): ";
            std::cin >> response;

            // add basic input validation
            // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }

            // clear input buffer
            std::cin.ignore();

            // Execute corresponding member function
            switch(response) {
            case 1:
                placeOrder();
                pause();
                break;
            case 2:
                placeExpressOrder();
                pause();
                break;
            case 3:
                processNextOrder();
                pause();
                break;
            case 4:
                pendingOrders();
                pause();
                break;
            case 5:
                pendingOrdersCount();
                pause();
                break;
            case 6: // Question 1.5 - This option exits the program
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

    // utility function for printing the system options menu
    static void printMenu() {
        std::cout << "\n-- Food Order Management System Options --\n";

        std::cout << "1) Place Order\n";
        std::cout << "2) Place Express Order\n";
        std::cout << "3) Process Next Order\n";
        std::cout << "4) Pending Orders\n";
        std::cout << "5) Pending Orders Count\n";
        std::cout << "6) Stop Program\n";

        std::cout << '\n';
    }

    // utility function for pausing on Windows systems only
    void pause() {
    #if defined(_WIN32)
        std::system("pause");
    #endif
    }
};

// Execute and test driver program
int main() {
    FoodOrderManagementSystem hoosierBurgers{"Hoosier Burgers"};
    hoosierBurgers.driverProgram();

    return 0;
}
