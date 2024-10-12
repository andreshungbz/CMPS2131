#include <iostream>

constexpr int MAX{5};
int stack[MAX];
int topIndex{-1};
int n_size{0};

void print();
bool isEmpty();
bool isFull();
void push(int value);
int pop();

int main()
{
    for (int i{1}; i <= 5; ++i) {
        push(i);
    }

    print();
    std::cout << "stack full? " << isFull() << '\n';

    for (int i{0}; i < 5; ++i) {
        pop();
    }

    print();
    std::cout << "stack empty? " << isEmpty() << '\n';

    return 0;
}

void print() {
    std::cout << "stack:";
    for (int i{0}; i < n_size; ++i) {
        std::cout << ' ' << stack[i];
    }
    std::cout << " [head]\n";
}

bool isEmpty() {
    return topIndex == -1;
}

bool isFull() {
    return n_size >= MAX;
}

void push(int value) {
    if (isFull()) {
        std::cout << "Stack full.\n";
        return;
    }

    ++topIndex;
    stack[topIndex] = value;
    ++n_size;
}

int pop() {
    // assumption: -999999 represents invalid value
    if (isEmpty()) {
        return -999999;
    }

    int popped = stack[topIndex];
    --topIndex;
    --n_size;

    return popped;
}
