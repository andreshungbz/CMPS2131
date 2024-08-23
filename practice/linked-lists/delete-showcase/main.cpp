#include <iostream>

class Node {
public:
    explicit Node(int value) : data{value}, next{nullptr} {}
    int data;
    Node* next;
};

class List {
public:
    ~List() {
        Node* currentPtr{head};
        Node* tempPtr{nullptr};

        while (currentPtr != nullptr) {
            tempPtr = currentPtr;
            currentPtr = currentPtr->next;
            delete tempPtr;
        }

        std::cout << "All nodes destroyed\n";
    }

    void insertAtFront(int value) {
        Node* newPtr{new Node{value}};
        newPtr->next = head;
        head = newPtr;
    }

    void insertAtBack(int value) {
        Node* newPtr{new Node{value}};

        if (isEmpty()) {
            head = newPtr;
        } else {
            Node* currentPtr{head};

            while (currentPtr->next != nullptr) {
                currentPtr = currentPtr->next;
            }

            currentPtr->next = newPtr;
        }
    }

    // adds node after node at given position
    void insert(int position, int value) {
        // invalid position
        if (position < 1) {
            std::cerr << "Invalid position\n";
            return;
        }

        // position 1 essentially is inserting at front
        if (position == 1) {
            insertAtFront(value);
            return;
        }

        Node* currentPtr{head};
        // - 2 for traversal adjustment
        // e.g. to add 3rd node, we need to reach node 2, which is 1 away from head node
        for (int i{position}; (i - 2) > 0; --i) {
            if (currentPtr->next != nullptr) { // if position is larger than list length, stay at last node
                currentPtr = currentPtr->next;
            }
        }

        // if we're at the last node, it is essentially insert at back
        if (currentPtr->next == nullptr) {
            insertAtBack(value);
            return;
        }

        // add new node accounting for linking node that goes after the new one
        Node* newPtr{new Node{value}};
        newPtr->next = currentPtr->next;
        currentPtr->next = newPtr;
    }

    void removeAtFront() {
        if (isEmpty()) {
            std::cerr << "List is empty.\n";
            return;
        }

        Node* tempPtr{head};
        head = head->next;
        delete tempPtr;

    }

    void removeAtBack() {
        if (isEmpty()) {
            std::cerr << "List is empty.\n";
            return;
        }

        // if there is only one node in the list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* currentPtr{head};
        // move pointer to second to last node
        while (currentPtr->next->next != nullptr) {
            currentPtr = currentPtr->next;
        }

        // delete last node from second-to-last node
        delete currentPtr->next;
        // set second-to-last node as last node
        currentPtr->next = nullptr;
    }

    // removes node at given position
    void remove(int position) {
        if (position < 1) {
            std::cerr << "Invalid position\n";
            return;
        }

        if (position == 1) {
            removeAtFront();
            return;
        }

        Node* currentPtr{head};
        // - 2 for traversal adjustment
        // e.g. to delete 3rd node, we need to reach node 2, which is 1 away from head node
        for (int i{position}; (i - 2) > 0; --i) {
            if (currentPtr->next->next != nullptr) { // if position is larger than list length, stay at last node
                currentPtr = currentPtr->next;
            }
        }

        // if we're at the second-to-last node, it is essentially remove at back
        if (currentPtr->next == nullptr) {
            removeAtBack();
            return;
        }

        // remove node accounting for linking node that takes it position
        Node* tempPtr{currentPtr->next};
        currentPtr->next = currentPtr->next->next;
        delete tempPtr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void print() {
        Node* currentPtr{head};

        while (currentPtr != nullptr) {
            std::cout << ' ' << currentPtr->data;
            currentPtr = currentPtr->next;
        }

        std::cout << '\n';
    }
private:
    Node* head{nullptr};
};

int main() {
    List list{};

    list.insertAtFront(2);
    list.insertAtFront(1);
    list.insertAtBack(3);
    list.insertAtBack(4);

    std::cout << "Initial List:";
    list.print();

    std::cout << "Add 5 as 3rd Node:";
    list.insert(3, 5);
    list.print();

    std::cout << "Remove item at front:";
    list.removeAtFront();
    list.print();

    std::cout << "Remove item at back:";
    list.removeAtBack();
    list.print();

    std::cout << "Remove 2nd Node:";
    list.remove(2);
    list.print();

    return 0;
}
