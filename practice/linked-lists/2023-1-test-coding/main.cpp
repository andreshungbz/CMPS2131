#include <iostream>

// node for doubly-linked list
class Node {
public:
    Node* prev{nullptr};
    char data;
    Node* next{nullptr};
};

// basic functions
void insertAtEnd(Node*& head, char value);
void deleteList(Node*& head);
void printList(const Node* head);
// functions for question
bool isPalindrome(Node* head);
bool isCircular(Node* head);
// extra tests
void testIsCircular(Node* head);

int main() {
    std::cout << std::boolalpha;

    // testing words for being palindromes

    Node* word{nullptr};
    insertAtEnd(word, 't');
    insertAtEnd(word, 'a');
    insertAtEnd(word, 'c');
    insertAtEnd(word, 'o');
    insertAtEnd(word, 'c');
    insertAtEnd(word, 'a');
    insertAtEnd(word, 't');

    std::cout << "word: ";
    printList(word);
    std::cout << "isPalindrome: " << isPalindrome(word) << '\n';

    Node* word2{nullptr};
    insertAtEnd(word2, 'd');
    insertAtEnd(word2, 'o');
    insertAtEnd(word2, 'g');
    insertAtEnd(word2, 'g');
    insertAtEnd(word2, 'y');

    std::cout << "word: ";
    printList(word2);
    std::cout << "isPalindrome: " << isPalindrome(word2) << '\n';

    // testing for circular linked list

    std::cout << "\nIs current linked list circular? " << isCircular(word) << '\n';
    testIsCircular(word);

    // clear allocated memory

    deleteList(word);
    deleteList(word2);

    return 0;
}

void insertAtEnd(Node*& head, char value) {
    Node* newPtr{new Node()};
    newPtr->data = value;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newPtr;
    newPtr->prev = currentPtr;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
}

void printList(const Node* head) {
    while (head != nullptr) {
        std::cout << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

bool isPalindrome(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* ptrA{head};
    Node* ptrB{head};
    int length{1};

    while (ptrB->next != nullptr) {
        ptrB = ptrB->next;
        ++length;
    }

    int counter{length/2};
    for (int i{0}; i < counter; ++i) {
        if (ptrA->data != ptrB->data) {
            return false;
        }

        ptrA = ptrA->next;
        ptrB = ptrB->prev;
    }

    return true;
}

bool isCircular(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* firstPtr{head};
    Node* currentPtr{head};
    while (true) {
        if (currentPtr == nullptr) {
            return false;
        }

        if (currentPtr->next == firstPtr) {
            return true;
        }

        currentPtr = currentPtr->next;
    }
}

void testIsCircular(Node* head) {
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // make list circular
    currentPtr->next = head;
    head->prev = currentPtr;

    std::cout << "Does testIsCircular pass? " << isCircular(head) << '\n';

    // revert back to non-circular
    currentPtr->next = nullptr;
    head->prev = nullptr;
}