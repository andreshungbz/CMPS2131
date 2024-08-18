// A simple stack program

#include <iostream>
#include "Stackcomposition.h" // Stack class definition

int main() {
    Stack<int> intStack; // create Stack of ints

    std::cout << "processing an integer Stack\n";

    // push integers onto intStack
    for (int i{0}; i < 3; ++i) {
        intStack.push(i);
        intStack.printStack();
    }

    int popInteger; // store int popped from stack

    // pop integers from intStack
    while (!intStack.isStackEmpty()) {
        intStack.pop(popInteger);
        std::cout << popInteger << " popped from stack\n";
        intStack.printStack();
    }

    Stack<double> doubleStack; // create Stack of doubles
    double value{1.1};

    std::cout << "processing a double Stack\n";

    for (int j{0}; j < 3; ++j) {
        doubleStack.push(value);
        doubleStack.printStack();
        value += 1.1;
    }

    double popDouble; // store double popped from stack

    // pop floating-point values from doubleStack
    while (!doubleStack.isStackEmpty()) {
        doubleStack.pop(popDouble);
        std::cout << popDouble << " popped from stack\n";
        doubleStack.printStack();
    }
}