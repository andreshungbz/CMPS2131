// Exercise 19.6 Concatenating Lists

#include <iostream>
#include "List.h"

template <typename T>
void concatenate(List<T>& a, const List<T>& b) {
    // don't make a deep copy
    // gives error: free(): double free detected in tcache 2
    // a.lastPtr->nextPtr = b.firstPtr;
    // a.lastPtr = b.lastPtr;

    // deep copy method
    ListNode<T>* currentPtr{b.firstPtr};

    while (currentPtr != nullptr) {
        a.insertAtBack(currentPtr->getData());
        currentPtr = currentPtr->nextPtr;
    }
}

int main() {
    List<int> list1{};
    List<int> list2{};

    for (int i{1}; i <= 10; ++i) {
        list1.insertAtBack(i);
    }

    for (int i{11}; i <= 20; ++i) {
        list2.insertAtBack(i);
    }

    std::cout << "List 1:\n";
    list1.print();

    std::cout << "List 2:\n";
    list2.print();

    std::cout << "Concatenated List 2 to List 1:\n";
    concatenate(list1, list2);
    list1.print();

    return 0;
}
