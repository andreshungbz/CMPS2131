#include <iostream>

constexpr int MAX{5};
int stack[MAX];
int topIndex{-1};

void printStack() {
    std::cout << "Stack:";
    for (int i{0}; i < topIndex + 1; ++i) {
        std::cout << ' ' << stack[i];
    }
    std::cout << '\n';
}

bool isFull() {
    return topIndex >= MAX - 1;
}

bool isEmpty() {
    return topIndex == -1;
}

int size() {
    return topIndex + 1;
}

void push(int value) {
    if (isFull()) {
        std::cout << "Stack is full.'\n";
        return;
    }

    stack[topIndex + 1] = value;
    ++topIndex;
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty.'\n";
        return;
    }

    --topIndex;
}

void pushFront(int value) {
    if (isFull()) {
        std::cout << "Stack is full.'\n";
        return;
    }

    for (int i{size()}; i > 0; --i) {
        stack[i] = stack[i - 1];
    }

    stack[0] = value;
    ++topIndex;
}

void popFront() {
    if (isEmpty()) {
        std::cout << "Stack is empty.'\n";
        return;
    }

    for (int i{0}; i < size() - 1; ++i) {
        stack[i] = stack[i + 1];
    }

    --topIndex;
}

int main()
{
    pushFront(1);
    pushFront(2);
    pushFront(3);

    printStack();
    std::cout << "Size: " << size() << '\n';

    popFront();
    popFront();

    printStack();
    std::cout << "Size: " << size() << '\n';

    return 0;
}
