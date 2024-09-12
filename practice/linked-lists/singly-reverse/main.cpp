#include <iostream>

// Node for singly-linked list
class Node {
public:
    int data;
    Node* next;
};

// helper functions
void printList(const Node* head);
void deleteList(Node*& head);
void insertAtEnd(Node*& head, int value);

void reverseList(Node*& head);

int main() {
    Node* listHead{nullptr};
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    printList(listHead);

    std::cout << "Reverse List:";
    reverseList(listHead);
    printList(listHead);

    deleteList(listHead);

    return 0;
}

void printList(const Node* head) {
    if (head == nullptr) {
        std::cout << "[Empty list]";
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

void deleteList(Node*& head) {
    // empty list
    if (head == nullptr) {
        return;
    }

    // traverse through the list, deleting every node using a temporary pointer
    Node* currentPtr{head};
    while (currentPtr != nullptr) {
        Node* tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        delete tempPtr;
    }

    // reset original list
    head = nullptr;
}

void insertAtEnd(Node*& head, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    // empty list
    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // create a pointer to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // insert node at the end
    currentPtr->next = newPtr;
}

void reverseList(Node*& head) {
    // empty list or list with one item
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* previousPtr{nullptr};
    Node* currentPtr{head};
    Node* nextPtr{nullptr};

    while (currentPtr != nullptr) {
        nextPtr = currentPtr->next;
        currentPtr->next = previousPtr;
        previousPtr = currentPtr;
        currentPtr = nextPtr;
    }

    // reassign head
    head = previousPtr;
}