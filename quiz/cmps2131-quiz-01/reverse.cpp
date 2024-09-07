#include <iostream>

// Node for doubly-linked list
class Node {
public:
    Node* prev;
    int data;
    Node* next;
};

void print(const Node* head);
void insertAtEnd(Node*& head, int value);
void reverse(Node* head);

int main() {
    Node* listHead{nullptr};
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    print(listHead);

    std::cout << "Reverse List:";
    reverse(listHead);
    print(listHead);

    return 0;
}

void print(const Node* head) {
    if (head == nullptr) {
        std::cout << "[Empty list]";
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

void insertAtEnd(Node*& head, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->next = nullptr;
    newPtr->data = value;

    // empty list
    if (head == nullptr) {
        head = newPtr;
        newPtr->prev = nullptr;
        return;
    }

    // create pointer to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // insert node at the end and link next and prev
    newPtr->prev = currentPtr;
    currentPtr->next = newPtr;
}

void reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    int length{1};
    Node* ptrA{head};
    Node* ptrB{head};
    while (ptrB->next != nullptr) {
        ptrB = ptrB->next;
        ++length;
    }

    int counter{length/2};
    for (int i{0}; i < counter; ++i) {
        int temp{ptrA->data};
        ptrA->data = ptrB->data;
        ptrB->data = temp;

        ptrA = ptrA->next;
        ptrB = ptrB->prev;
    }
}