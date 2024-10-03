#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printQueue(const Node* head) {
    std::cout << "Queue:";
    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }
    std::cout << '\n';
}

void deleteQueue(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;
    }
}

void enqueue(Node*& head, Node*& tail, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (head == nullptr || tail == nullptr) {
        head = newPtr;
        tail = newPtr;
        return;
    }

    tail->next = newPtr;
    tail = newPtr;
}

void dequeue(Node*& head, Node*& tail) {
    if (head == nullptr || tail == nullptr) {
        std::cout << "Queue is empty.\n";
        return;
    }

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node* tempPtr{head};
    head = head->next;
    delete tempPtr;
}

int* front(const Node* head) {
    return head != nullptr ? new int(head->data) : nullptr;
}

int* back(const Node* tail) {
    return tail != nullptr ? new int(tail->data) : nullptr;
}

int main() {
    Node* queueHead{nullptr};
    Node* queueTail{nullptr};

    enqueue(queueHead, queueTail, 1);
    enqueue(queueHead, queueTail, 2);
    enqueue(queueHead, queueTail, 3);

    printQueue(queueHead);

    if (int* intPtr{front(queueHead)}) {
        std::cout << "Front: " << *intPtr << '\n';
    } else {
        std::cout << "Front: " << "[empty]" << '\n';
    }

    if (int* intPtr2{back(queueTail)}) {
        std::cout << "Back: " << *intPtr2 << '\n';
    } else {
        std::cout << "Back: " << "[empty]" << '\n';
    }

    dequeue(queueHead, queueTail);
    dequeue(queueHead, queueTail);

    printQueue(queueHead);

    return 0;
}
