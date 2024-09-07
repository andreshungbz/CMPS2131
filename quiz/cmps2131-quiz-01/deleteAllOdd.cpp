#include <iostream>

// Node for singly-linked list
class Node {
public:
    int data;
    Node* next;
};

// helper functions
void print(const Node* head);
void insertAtEnd(Node*& head, int value);
void deleteList(Node*& head);
void deleteAllOdd(Node*& head);

int main() {
    Node* listHead{nullptr};
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }

    std::cout << "Initial List:";
    print(listHead);

    std::cout << "All Odd Numbers Deleted:";
    deleteAllOdd(listHead);
    print(listHead);

    deleteList(listHead);

    return 0;
}

void print(const Node* head) {
    if (head == nullptr) {
        std::cout << "[Empty list]";
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

void deleteAllOdd(Node*& head) {
    while (head != nullptr && head->data % 2 == 1) {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
    }

    Node* currentPtr = head;
    while (currentPtr != nullptr && currentPtr->next != nullptr) {
        if (currentPtr->next->data % 2 == 1) {
            Node* tempPtr = currentPtr->next;
            currentPtr->next = currentPtr->next->next;
            delete tempPtr;
        } else {
            currentPtr = currentPtr->next;
        }
    }
}