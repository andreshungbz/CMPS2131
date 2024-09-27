#include <iostream>

constexpr int MAX{5};
int top{0};
int array[MAX];

bool isFull() {
    if (top >= MAX) {
        std::cout << "Stack Overflow error. ";
        return true;
    }

    return false;
}

void push(int value) {
    if (!isFull()) {
        array[top++] = value;
    }
}

int numberofelements() {
    return top;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "Stack isFull?: " << isFull() << '\n';

    for (int i{1}; i <= 5; ++i) {
        push(i);
    }

    std::cout << "Stack isFull?: " << isFull() << '\n';
    std::cout << "Stack numberofelements: " << numberofelements() << '\n';

    return 0;
}
