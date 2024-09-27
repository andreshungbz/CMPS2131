#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printQueue(const Node* head) {
    if (head == nullptr) {
        std::cout << "[EMPTY]";
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

bool isEmpty(const Node* head) {
    return head == nullptr;
}

void enqueue(Node*& head, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // create point to last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newPtr;
}

void dequeue(Node*& head) {
    // empty node
    if (head == nullptr) {
        return;
    }

    Node* tempPtr{head};
    head = head->next;
    delete tempPtr;
}

int main() {
    std::cout << std::boolalpha;

    Node* queueHead{nullptr};

    std::cout << "isEmpty: " << isEmpty(queueHead) << '\n';

    for (int i{1}; i <= 5; ++i) {
        enqueue(queueHead, i);
    }
    std::cout << "Queue:";
    printQueue(queueHead);

    dequeue(queueHead);
    dequeue(queueHead);
    std::cout << "Queue:";
    printQueue(queueHead);

    std::cout << "isEmpty: " << isEmpty(queueHead) << '\n';

    return 0;
}
