// Manipulating a singly linked list

#include <iostream>
#include <string>
#include "List.h"

// display program instructions to users
void instructions() {
    std::cout << "Enter one of the following:\n"
                << "  1 to insert at beginning of list\n"
                << "  2 to insert at end of list\n"
                << "  3 to delete from beginning of list\n"
                << "  4 to delete from end of list\n"
                << "  5 to end list processing\n";
}

// function to test a list
template<typename T>
void testList(List<T>& listObject, const std::string& typeName) {
    std::cout << "Testing a List of " << typeName << " values\n";
    instructions(); // display instructions

    int choice; // store user choice
    T value; // store input value

    do { // perform user-selected actions
        std::cout << "? ";
        std::cin >> choice;

        switch (choice) {
        case 1: // insert at beginning
            std::cout << "Enter " << typeName << ": ";
            std::cin >> value;
            listObject.insertAtFront(value);
            listObject.print();
            break;
        case 2: // insert at end
            std::cout << "Enter " << typeName << ": ";
            std::cin >> value;
            listObject.insertAtBack(value);
            listObject.print();
            break;
        case 3: // remove from beginning
            if (listObject.removeFromFront(value)) {
                std::cout << value << " removed from list\n";
            }

            listObject.print();
            break;
        case 4: // remove from end
            if (listObject.removeFromBack(value)) {
                std::cout << value << " removed form list\n";
            }

            listObject.print();
            break;
        default:
            break;
        }
    } while (choice < 5);

    std::cout << "End list test\n\n";
}

int main() {
    // test List of int values
    List<int> integerList;
    testList(integerList, "integer");

    // test List of double values
    List<double> doubleList;
    testList(doubleList, "double");
}