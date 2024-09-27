#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;
    }
}

void insertAtEnd(Node*& head, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (head == nullptr) {
        head = newPtr;
        return;
    }

    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newPtr;
}

void deleteAllEven(Node*& head) {
    Node* dummyNodePtr{new Node()};
    dummyNodePtr->next = head;

    Node* currentPtr{dummyNodePtr};
    while(currentPtr != nullptr && currentPtr->next != nullptr) {
        if (currentPtr->next->data % 2 == 0) {
            Node* tempPtr{currentPtr->next};

            if (currentPtr->next == head) {
                head = currentPtr->next->next;
            }

            currentPtr->next = currentPtr->next->next;
            delete tempPtr;
        } else {
            currentPtr = currentPtr->next;
        }
    }

    delete dummyNodePtr;
}

int main() {
    Node* listHead{nullptr};
    for (int i{2}; i <= 7; i = i+2) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    printList(listHead);

    std::cout << "\nChanged List:";
    deleteAllEven(listHead);
    printList(listHead);

    deleteList(listHead);
    return 0;
}
