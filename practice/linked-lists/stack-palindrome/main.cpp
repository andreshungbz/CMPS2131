#include <iostream>

// Node for singly-linked list
class Node {
public:
    char data;
    Node* next{nullptr};
};

void printStack(const Node* head);
void deleteStack(Node*& head);
// stack functions
void push(Node*& head, char value);
char pop(Node*& head);

bool isPalindrome(const char* word);

int main() {
    std::cout << std::boolalpha;

    char word[80] {"racecar"};
    std::cout << "Word: " << word << '\n';
    std::cout << "isPalindrome: " << isPalindrome(word) << '\n';

    char word2[80] {"apple"};
    std::cout << "\nWord: " << word2 << '\n';
    std::cout << "isPalindrome: " << isPalindrome(word2) << '\n';

    return 0;
}

void printStack(const Node* head) {
    if (head == nullptr) {
        std::cout << " [Empty]" << '\n';
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

void deleteStack(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;
    }
}

void push(Node*& head, char value) {
    Node* newPtr{new Node()};
    newPtr->data = value;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    newPtr->next = head;
    head = newPtr;
}

char pop(Node*& head) {
    if (head == nullptr) {
        return '\0';
    }

    char temp{head->data};

    Node* tempPtr{head};
    head = head->next;
    delete tempPtr;

    return temp;
}

bool isPalindrome(const char* word) {
    // utilize a stack
    Node* checkStack{nullptr};

    // populate stack with every letter of word minus null terminator
    const char* currentPtr{word};
    while (*currentPtr != '\0') {
        push(checkStack, *currentPtr);
        ++currentPtr;
    }

    // popped letter starts from the end of the word
    char temp{pop(checkStack)}; // do this again for using '.' as end point
    // traverse word from beginning again
    currentPtr = word;
    while (*currentPtr != '\0' || temp != '\0') { // change to *currentPtr != '.' for using '.' as end point
        if (*currentPtr != temp) {
            // when short-circuiting, delete rest of stack
            deleteStack(checkStack);
            return false;
        }

        temp = pop(checkStack);
        ++currentPtr;
    }

    return true;
}