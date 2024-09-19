#include <iostream>

// Node for singly-linked list
class Node {
public:
    int data;
    Node* next;
};

// starter function for driver
void printList(const Node* head);

// created functions
void insertAtEnd(Node*& head, int value);
void deleteList(Node*& head);

// function for question
void deleteMiddle(Node*& head);

int main() {
    // list with odd length
    Node* listHead{nullptr};
    for (int i{1}; i<= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    printList(listHead);

    // testing deleteMiddle
    deleteMiddle(listHead);
    std::cout << "deleteMiddle:";
    printList(listHead);

    // list with even length
    Node* listHead2{nullptr};
    insertAtEnd(listHead2, 2);
    insertAtEnd(listHead2, 4);
    insertAtEnd(listHead2, 6);
    insertAtEnd(listHead2, 7);
    insertAtEnd(listHead2, 5);
    insertAtEnd(listHead2, 1);
    std::cout << "List:";
    printList(listHead2);

    // testing deleteMiddle
    deleteMiddle(listHead2);
    std::cout << "deleteMiddle:";
    printList(listHead2);

    // deallocate memory
    deleteList(listHead);
    deleteList(listHead2);

    return 0;
}

void printList(const Node* head) {
    // empty list
    if (head == nullptr) {
        std::cout << " [empty]\n";
        return;
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }
    std::cout << '\n';
}

void insertAtEnd(Node*& head, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newPtr;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;
    }
}

void deleteMiddle(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: empty list.\n";
        return;
    }

    // if list has only one element, delete it
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // list has at least 2 elements from this point

    // get the length in order to calculate traversals needed
    int length{0};
    Node* lengthPtr{head};
    while (lengthPtr != nullptr) {
        ++length;
        lengthPtr = lengthPtr->next;
    }

    // traverse a node to the one before the one to delete
    // traversals calculation works for both even and odd lengths
    int traversals{(length / 2) - 1};
    Node* currentPtr{head};
    for (int i{0}; i < traversals; ++i) {
        currentPtr = currentPtr->next;
    }

    // delete middle node
    Node* tempPtr{currentPtr->next};
    currentPtr->next = currentPtr->next->next;
    delete tempPtr;
}