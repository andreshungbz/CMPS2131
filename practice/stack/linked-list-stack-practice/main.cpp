#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printStack(const Node* head) {
    std::cout << "Stack:";
    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }
    std::cout << '\n';
}

void deleteStack(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;
    }
}

void push(Node*& head, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    newPtr->next = head;
    head = newPtr;
}

int pop(Node*& head) {
    if (head == nullptr) {
        return -99999;
    }

    Node* tempPtr{head};
    int value = tempPtr->data;
    head = head->next;
    delete tempPtr;

    return value;
}

int main() {
    Node* listHead{nullptr};

    push(listHead, 1);
    push(listHead, 2);
    push(listHead, 3);

    printStack(listHead);

    pop(listHead);
    pop(listHead);

    printStack(listHead);

    deleteStack(listHead);

    return 0;
}
