#include <iostream>
#include <limits>

int timestamp() {
    static int time{-1};

    if (time != std::numeric_limits<int>::max()) {
        return ++time;
    }

    return std::numeric_limits<int>::max();
}

class Node {
public:
    int data{};
    int priority{};
    Node* next{nullptr};
};

class StackPriorityQueue {
public:
    void Push(int value) {
        Node* newPtr{new Node()};
        newPtr->data = value;
        newPtr->priority = timestamp();

        if (firstPtr == nullptr || lastPtr == nullptr) {
            firstPtr = lastPtr = newPtr;
            return;
        }

        if (firstPtr->priority < newPtr->priority) {
            newPtr->next = firstPtr;
            firstPtr = newPtr;
            return;
        }

        if (lastPtr->priority > newPtr->priority) {
            lastPtr->next = newPtr;
            lastPtr = newPtr;
            return;
        }

        Node* currentPtr{firstPtr};
        while (currentPtr->next != nullptr && currentPtr->next->priority > newPtr->priority) {
            currentPtr = currentPtr->next;
        }

        newPtr->next = currentPtr->next;
        currentPtr->next = newPtr;
    }

    void Pop() {
        if (firstPtr == nullptr || lastPtr == nullptr) {
            std::cout << "Stack is empty.\n";
            return;
        }

        Node* tempPtr{firstPtr};

        if (firstPtr == lastPtr) {
            delete tempPtr;
            firstPtr = lastPtr = nullptr;
            return;
        }

        firstPtr = firstPtr->next;
        delete tempPtr;
    }

    void printStack() {
        Node* firstCopy{firstPtr};

        std::cout << "Stack:";
        while (firstCopy != nullptr) {
            std::cout << " [" << firstCopy->data << "|p" << firstCopy->priority << ']';
            firstCopy = firstCopy->next;
        }
        std::cout << '\n';
    }
private:
    Node* firstPtr{nullptr};
    Node* lastPtr{nullptr};
};

int main() {
    StackPriorityQueue stack{};

    stack.Push(10);
    stack.Push(11);
    stack.Push(12);

    stack.printStack();

    stack.Pop();
    stack.Pop();

    stack.printStack();

    // 8.a The highest-priority element is always the last item to be added to the stack.
    // This is because of the way the incrementing timestamp is always used when assigning priority
    // and that higher positive number is used for higher priority

    // By utilizing both a firstPtr and lastPtr, the Big-O of Push() is effectively O(1) as
    // by nature of using timestamp(), newly added items are always added at the front.
    // The Big-O of Pop() is also O(1) as the popped item is always at the front.
    // This is typically same for a standard stack implementation using the head for pushing
    // and popping items.

    return 0;
}
