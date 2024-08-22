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
    ~List() {
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

    void insertAtFront(const NODETYPE& value) {
        ListNode<NODETYPE>* newPtr{getNewNode(value)};

        if (isEmpty()) {
            firstPtr = newPtr;
            lastPtr = newPtr;
        } else {
            newPtr->nextPtr = firstPtr;
            firstPtr = newPtr;
        }
    };

    void insertAtBack(const NODETYPE& value) {
        ListNode<NODETYPE>* newPtr{getNewNode(value)};

        if (isEmpty()) {
            firstPtr = newPtr;
            lastPtr = newPtr;
        } else {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
        }
    };

    bool removeFromFront(NODETYPE& value) {
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

    bool removeFromBack(NODETYPE& value) {
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

    [[nodiscard]] bool isEmpty() const {
        return firstPtr == nullptr;
    };

    void print() const {
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

    // extra function for exercise 19-07
    void insertNode(ListNode<NODETYPE>* nodeBefore, const NODETYPE& value) {
        ListNode<NODETYPE>* newPtr{getNewNode(value)};
        newPtr->nextPtr = nodeBefore->nextPtr;
        nodeBefore->nextPtr = newPtr;
    }

private:
    ListNode<NODETYPE>* firstPtr{nullptr};
    ListNode<NODETYPE>* lastPtr{nullptr};

    // utility function to allocate new node
    ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
        return new ListNode<NODETYPE>{value}; // new syntax returns a pointer to the object
    }
};

#endif // LIST_H
