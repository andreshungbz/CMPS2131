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

        if (isEmpty()) {
            head = newPtr;
        } else {
            newPtr->next = head;
            head = newPtr;
        }
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
        Node* newPtr{new Node{value}};
        int traversals{position - 1};

        if (traversals == 0) { // empty list
            head = newPtr;
        } else if (traversals < 0) { // beginning of list
            newPtr->next = head;
            head = newPtr;
        } else { // traversals necessary
            Node* currentPtr{head};

            while (traversals) {
                // don't traverse past the end of list
                if (currentPtr->next != nullptr) {
                    currentPtr = currentPtr->next;
                }

                --traversals;
            }

            // new node is at the end of list
            if (currentPtr->next == nullptr) {
                currentPtr->next = newPtr;
            } else { // there is a node after to link to new node
                newPtr->next = currentPtr->next;
                currentPtr->next = newPtr;
            }
        }
    }

    void removeAtFront() {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
        } else {
            Node* tempPtr{head};
            head = head->next;
            delete tempPtr;
        }

    }

    void removeAtBack() {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
        } else {
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
    }

    // removes node at given position
    void remove(int position) {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
        } else {
            Node* tempPtr{nullptr};
            Node* currentPtr{head};
            int traversals{position - 1};

            if (traversals == 0) { // delete first node
                removeAtFront();
            } else {
                while (traversals - 1 > 0) {
                    if (currentPtr->next != nullptr) {
                        currentPtr = currentPtr->next;
                    }

                    --traversals;
                }

                // remove node at the end of list
                if (currentPtr->next == nullptr) {
                    removeAtBack();
                } else { // there is a node after to link to the node before
                    tempPtr = currentPtr->next;
                    currentPtr->next = currentPtr->next->next;
                    delete tempPtr;
                }
            }
        }
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

    std::cout << "Add 5 after 3rd Node:";
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

    std::cout << "Remove 2nd Node:";
    list.remove(2);
    list.print();

    std::cout << "Remove 2nd Node:";
    list.remove(1);
    list.print();

    return 0;
}
