#include <cstring>
#include <iostream>
#include <string>
#include "Stack.h"

void reverseCharStringDemo() {
    // using c-style strings
    char sentence[100] {};
    std::cout << "Enter sentence: ";
    std::cin.getline(sentence, 100);

    Stack<char*> charStack{};
    char* tokenPtr{std::strtok(sentence, " ")};
    while (tokenPtr != nullptr) {
        charStack.push(tokenPtr);
        tokenPtr = std::strtok(nullptr, " ");
    }
    // charStack.printStack();

    char* word[50];
    while (charStack.pop(*word)) {
        std::cout << *word << '\n';
    }
}

void reverseStringDemo() {
    // using string class
    std::string sentence{};
    std::cout << "Enter sentence: ";
    std::getline(std::cin >> std::ws, sentence);

    Stack<std::string> stringStack{};
    std::size_t position{0};
    while ((position = sentence.find(' ')) != std::string::npos) {
        stringStack.push(sentence.substr(0, position));
        sentence.erase(0, position + 1);
    }
    stringStack.push(sentence);

    std::string word;
    while (stringStack.pop(word)) {
        std::cout << word << '\n';
    }
}

int main() {
    reverseStringDemo();
    return 0;
}