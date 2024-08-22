// Exercise 19.7 Merging Ordered Lists

#include <iostream>
#include "List.h"

template<typename T>
void merge(List<T>& a, const List<T>& b, const List<T>& c) {
    // add all values from first list (assume ordered)
    ListNode<T>* currentPtr{b.firstPtr}; // pointer to iterate through first list
    while (currentPtr != nullptr) {
        a.insertAtBack(currentPtr->getData());
        currentPtr = currentPtr->nextPtr;
    }

    // add all values from second list
    currentPtr = c.firstPtr; // pointer to iterate through second list
    while (currentPtr != nullptr) {
        T item{currentPtr->getData()}; // value to add ultimately

        // pointer to loop through current merge list
        // this is necessary as the node position could be anywhere in the current list
        // resets to beginning of merge list with every iteration of currentPtr
        ListNode<T>* tempPtr{a.firstPtr};

        // insert at beginning if first node's value is larger
        if (item <= tempPtr->getData()) {
            a.insertAtFront(item);

            // go to next item in second list to add to merge list
            currentPtr = currentPtr->nextPtr;
            continue;
        }

        // loop through merge list
        while (tempPtr != nullptr) {
            // insert at end if at the end (assume ordered)
            if (tempPtr->nextPtr == nullptr) {
                a.insertAtBack(item);

                // go to next iteration of currentPtr
                break;
            }

            // insert at the given node if the node after has a larger value
            if (item < tempPtr->nextPtr->getData()) {
                a.insertNode(&(*tempPtr), item);

                // go to next iteration of currentPtr
                break;
            }

            tempPtr = tempPtr->nextPtr;
        }

        currentPtr = currentPtr->nextPtr;
    }
}

int main() {
    List<int> list1{};
    List<int> list2{};

    for (int i{1}; i <= 10; i += 2) {
        list1.insertAtBack(i);
    }

    for (int i{2}; i <= 10; i += 2) {
        list2.insertAtBack(i);
    }

    std::cout << "Ordered List 1:\n";
    list1.print();

    std::cout << "Ordered List 2:\n";
    list2.print();

    std::cout << "Merged List 3:\n";
    List<int> list3{};
    merge(list3, list1, list2);
    list3.print();
}