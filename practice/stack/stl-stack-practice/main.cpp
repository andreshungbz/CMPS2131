#include <iostream>
#include <stack>

void printStack(std::stack<int> stackCopy) {
    std::cout << "Stack:";
    while (!stackCopy.empty()) {
        std::cout << ' ' << stackCopy.top();
        stackCopy.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::stack<int> stack{};

    stack.push(1);
    stack.push(2);
    stack.push(3);

    printStack(stack);
    std::cout << "Size: " << stack.size() << '\n';

    stack.pop();
    stack.pop();

    printStack(stack);
    std::cout << "Size: " << stack.size() << '\n';

    return 0;
}
