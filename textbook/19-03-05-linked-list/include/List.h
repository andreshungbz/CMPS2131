// List class-template definition

#ifndef LIST_H
#define LIST_H



#include <iostream>
#include "ListNode.h"

template<typename NODETYPE>
class List {
public:
    ~List(); // destructor
    void insertAtFront(const NODETYPE& value); // insert node at front of list
    void insertAtBack(const NODETYPE& value); // insert node at back of list
    bool removeFromFront(NODETYPE& value); // delete node from front of list
    bool removeFromBack(NODETYPE& value); // delete node from back of list
    bool isEmpty() const; // is List empty?
    void print() const; // display contents of List
private:
    ListNode<NODETYPE>* firstPtr{nullptr}; // pointer to first node
    ListNode<NODETYPE>* lastPtr{nullptr}; // pointer to last node
    ListNode<NODETYPE>* getNewNode(const NODETYPE& value); // utility function to allocate new node
};

// In C++, template classes and functions must be fully defined in the header file
// because the compiler needs to see the complete definition of the template when it
// instantiates it with specific types.

template<typename NODETYPE>
List<NODETYPE>::~List() {
    if (!isEmpty()) {
        std::cout << "Destroying nodes ...\n";

        ListNode<NODETYPE>* currentPtr{firstPtr};
        ListNode<NODETYPE>* tempPtr{nullptr};

        while (currentPtr != nullptr) { // delete remaining nodes
            tempPtr = currentPtr;
            std::cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }

    std::cout << "All nodes destroyed\n\n";
}

template<typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE& value) {
    ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

    if (isEmpty()) { // List is empty
        firstPtr = lastPtr = newPtr; // new list has only one node
    } else { // List not empty
        newPtr->nextPtr = firstPtr; // point new node to old 1st node
        firstPtr = newPtr; // aim firstPtr at new node
    }
}

template<typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& value) {
    ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

    if (isEmpty()) { // List is empty
        firstPtr = lastPtr = newPtr; // new list has only one node
    } else { // List is not empty
        lastPtr->nextPtr = newPtr; // update previous last node
        lastPtr = newPtr; // new last node
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& value) {
    if (isEmpty()) { // List is empty
        return false; // delete unsuccessful
    } else {
        ListNode<NODETYPE>* tempPtr{firstPtr}; // hold item to delete

        if (firstPtr == lastPtr) {
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
        } else {
            firstPtr = firstPtr->nextPtr; // point to previous 2nd node
        }

        value = tempPtr->data; // return data being removed
        delete tempPtr; // reclaim previous front node
        return true; // delete successful
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE& value) {
    if (isEmpty()) { // List is empty
        return false; // delete unsuccessful
    } else {
        ListNode<NODETYPE>* tempPtr{lastPtr}; // hold item to delete

        if (firstPtr == lastPtr) { // List has one element
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
        } else {
            ListNode<NODETYPE>* currentPtr{firstPtr};

            // locate second-to-last element
            while (currentPtr->nextPtr != lastPtr) {
                currentPtr = currentPtr->nextPtr; // move to next node
            }

            lastPtr = currentPtr; // remove last node; change lastPtr to second-to-last node
            currentPtr->nextPtr = nullptr; // this is now the last node
        }

        value = tempPtr->data; // return value from old last node
        delete tempPtr; // reclaim former last node
        return true; // delete successful
    }
}


template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const {
    return firstPtr == nullptr;
}

template<typename NODETYPE>
void List<NODETYPE>::print() const {
    if (isEmpty()) { // List is empty
        std::cout << "The list is empty\n\n";
        return;
    }

    ListNode<NODETYPE>* currentPtr{firstPtr};

    std::cout << "The list is: ";

    while (currentPtr != nullptr) { // get element data
        std::cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }

    std::cout << "\n\n";
}

template<typename NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& value) {
    return new ListNode<NODETYPE>{value};
}



#endif //LIST_H
