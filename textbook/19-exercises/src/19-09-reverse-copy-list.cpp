#include "List.h"

template <typename T>
List<T> createReverseList(const List<T>& list) {
    List<T> newList{};

    ListNode<T>* currentPtr{list.firstPtr};
    while (currentPtr != nullptr) {
        newList.insertAtFront(currentPtr->getData());
        currentPtr = currentPtr->nextPtr;
    }

    return newList;
}

int main() {
    List<int> list{};

    for (int i{1}; i <= 10; ++i) {
        list.insertAtBack(i);
    }

    list.print();

    List<int> listReverseCopy{createReverseList(list)};
    listReverseCopy.print();

    return 0;
}