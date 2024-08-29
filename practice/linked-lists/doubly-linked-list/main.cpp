#include <iostream>

class Node {
public:
    Node* prev{nullptr};
    int data;
    Node* next{nullptr};
};

void printList(Node* head) {
    std::cout << "List:";
    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }
    std::cout << '\n';
}

void insertAtFront(Node*& head, int value) {
    Node* newNode{new Node()};
    newNode->next = head;
    newNode->data = value;
    newNode->prev = nullptr;
    head = newNode;
}

void insertAtBack(Node* head, int value) {
    Node* newNode{new Node()};
    while (head->next != nullptr) {
        head = head->next;
    }
    newNode->next = nullptr;
    newNode->data = value;
    newNode->prev = head;
    head->next = newNode;
}

int main()
{
    Node* one{new Node()};
    Node* two{new Node()};
    Node* three{new Node()};

    Node* head{one};

    one->prev = nullptr;
    one->data = 1;
    one->next = two;

    two->prev = one;
    two->data = 2;
    two->next = three;

    three->prev = two;
    three->data = 3;
    three->next = nullptr;

    printList(head);
    insertAtFront(head, 4);
    printList(head);
    insertAtBack(head, 5);
    printList(head);

    delete one;
    delete two;
    delete three;

    return 0;
}
