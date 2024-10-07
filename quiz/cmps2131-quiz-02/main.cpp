#include <iostream>

// singly-linked list Node structure
class Node {
public:
    int data;
    Node* next;
};

// 2 pointers to keep track of front and rear of queue
// Question 2 sort of suggests that I keep these as global variables
Node* queueFront{nullptr};
Node* queueRear{nullptr};

// 3.1 check empty queue
bool isempty();

// 3.2 enqueue
void enqueue(int value);

// 3.3 dequeue
void dequeue();

// 3.4 print
void Print();

int main()
{
    int response{0};

    while (true) {
        Print();
        std::cout << "Enter positive number (-1 to stop): ";
        std::cin >> response;

        if (response < 0) {
            break;
        }

        enqueue(response);
    }

    int dequeueResponse{0};
    std::cout << "\nHow many to dequeue? ";
    std::cin >> dequeueResponse;

    if (dequeueResponse < 0) {
        dequeueResponse = 0;
    }

    for (int i{0}; i < dequeueResponse; ++i) {
        dequeue();
    }

    std::cout << "\nFinal Queue\n";
    Print();

    std::cout << '\n';

    return 0;
}

// 3.1 check empty queue
bool isempty() {
    return (queueFront == nullptr || queueRear == nullptr);
}

// 3.2 enqueue
void enqueue(int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (isempty()) {
        queueFront = newPtr;
        queueRear = newPtr;
        return;
    }

    queueRear->next = newPtr;
    queueRear = newPtr;
}

// 3.3 dequeue
void dequeue() {
    if (isempty()) {
        std::cout << "The queue is empty\n";
        return;
    }

    Node* tempPtr{queueFront};

    int element{queueFront->data};

    queueFront = queueFront->next;
    delete tempPtr;

    std::cout << "Element " << element << " has been dequeued\n";
}

// 3.4 print
void Print() {
    Node* frontCopy{queueFront};

    std::cout << "Queue:";

    if (queueFront == nullptr) {
        std::cout << " [empty]\n";
        return;
    }

    while (frontCopy != nullptr) {
        std::cout << ' ' << frontCopy->data;
        frontCopy = frontCopy->next;
    }
    std::cout << '\n';
}
