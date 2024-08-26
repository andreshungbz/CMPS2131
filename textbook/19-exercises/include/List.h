// List class-template definition

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"

template<typename NODETYPE>
class List {
    // friend declaration for exercise 19-06 to access private/protected members
    template<typename T>
    friend void concatenate(List<T>& a, const List<T>& b);

    // friend declaration for exercise 19-07
    template<typename T>
    friend void merge(List<T>& a, const List<T>& b, const List<T>& c);

public:
    ~List();
    void insertAtFront(const NODETYPE& value);
    void insertAtBack(const NODETYPE& value);
    bool removeFromFront(NODETYPE& value);
    bool removeFromBack(NODETYPE& value);
    [[nodiscard]] bool isEmpty() const;
    void print() const;

    // extra function for exercise 19-07
    void insertNode(ListNode<NODETYPE>* nodeBefore, const NODETYPE& value);

    // extra function for exercise 19-08
    void insertOrderedNode(const NODETYPE& value);

private:
    ListNode<NODETYPE>* firstPtr{nullptr};
    ListNode<NODETYPE>* lastPtr{nullptr};

    // utility function to allocate new node
    ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
        return new ListNode<NODETYPE>{value}; // new syntax returns a pointer to the object
    }
};

template<typename NODETYPE>
List<NODETYPE>::~List() {
    if (!isEmpty()) {
        std::cout << "Destroying nodes...\n";

        ListNode<NODETYPE>* tempPtr{nullptr};
        ListNode<NODETYPE>* currentPtr{firstPtr};

        while (currentPtr != nullptr) {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }

    std::cout << "All nodes destroyed\n\n";
};

template<typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE& value) {
    ListNode<NODETYPE>* newPtr{getNewNode(value)};

    if (isEmpty()) {
        firstPtr = newPtr;
        lastPtr = newPtr;
    } else {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }
};

template<typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& value) {
    ListNode<NODETYPE>* newPtr{getNewNode(value)};

    if (isEmpty()) {
        firstPtr = newPtr;
        lastPtr = newPtr;
    } else {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
};

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& value) {
    if (isEmpty()) {
        return false;
    }

    ListNode<NODETYPE>* tempPtr{firstPtr};

    if (firstPtr == lastPtr) {
        firstPtr = nullptr;
        lastPtr = nullptr;
    } else {
        firstPtr = firstPtr->nextPtr;
    }

    value = tempPtr->getData();
    delete tempPtr;
    return true;
};

template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE& value) {
    if (isEmpty()) {
        return false;
    }

    ListNode<NODETYPE>* tempPtr{lastPtr};
    ListNode<NODETYPE>* currentPtr{firstPtr};

    if (firstPtr == lastPtr) {
        firstPtr = nullptr;
        lastPtr = nullptr;
    } else {
        while (currentPtr->nextPtr != lastPtr) {
            currentPtr = currentPtr->nextPtr;
        }

        lastPtr = currentPtr;
        currentPtr->nextPtr = nullptr;
    }

    value = tempPtr->getData();
    delete tempPtr;
    return true;
};

template<typename NODETYPE>
[[nodiscard]] bool List<NODETYPE>::isEmpty() const {
    return firstPtr == nullptr;
};

template<typename NODETYPE>
void List<NODETYPE>::print() const {
    if (isEmpty()) {
        std::cout << "The list is empty.\n";
    }

    std::cout << "List:";

    ListNode<NODETYPE>* currentPtr{firstPtr};

    while (currentPtr != nullptr) {
        std::cout << ' ' << currentPtr->getData();
        currentPtr = currentPtr->nextPtr;
    }

    std::cout << "\n\n";
};

template<typename NODETYPE>
void List<NODETYPE>::insertNode(ListNode<NODETYPE>* nodeBefore, const NODETYPE& value) {
    ListNode<NODETYPE>* newPtr{getNewNode(value)};

    if (isEmpty()) {
        firstPtr = newPtr;
        lastPtr = newPtr;
    }

    newPtr->nextPtr = nodeBefore->nextPtr;
    nodeBefore->nextPtr = newPtr;
}

template<typename NODETYPE>
void List<NODETYPE>::insertOrderedNode(const NODETYPE& value) {
    if (isEmpty()) {
        ListNode<NODETYPE>* newPtr{getNewNode(value)};
        firstPtr = newPtr;
        lastPtr = newPtr;
        return;
    }

    if (firstPtr->getData() >= value) {
        insertAtFront(value);
        return;
    }

    if (lastPtr->getData() <= value) {
        insertAtBack(value);
        return;
    }

    ListNode<NODETYPE>* currentPtr{firstPtr};
    while (true) {
        if (currentPtr->nextPtr->getData() >= value) {
            insertNode(currentPtr, value);
            return;
        }

        currentPtr = currentPtr->nextPtr;
    }
}

#endif // LIST_H
