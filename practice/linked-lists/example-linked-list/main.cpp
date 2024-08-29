// Singly-linked List Demo

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int value;
    Node* next;
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Print linked list in reverse
void printListReverse(Node* head) {
    if (head == nullptr) {
        return;
    }

    printListReverse(head->next);
    std::cout << head->value << ", ";
}

// Function to print only odd numbers
void printOddNumbers(Node* head) {
    Node* current{head};
    while (current != nullptr) {
        int item{current->value};

        if (item % 2 == 1) {
            std::cout << item << ' ';
        }

        current = current->next;
    }

    std::cout << '\n';
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node*& head, int newValue) {
    Node* newNode = new Node();
    newNode->value = newValue;

    newNode->next = head; // Point new node's next to the current head
    head = newNode;       // Update head to point to the new node
}

// Function to insert a new node at the end of the list
void insertNodeAtEnd(Node* head, int newValue) {
    // traverse to end of list
    Node* current{head};
    while (current->next != nullptr) {
        current = current->next;
    }

    // create and set new node
    Node* newNodePtr{new Node{}};
    newNodePtr->value = newValue;
    newNodePtr->next = nullptr;

    // attach to list
    current->next = newNodePtr;
}

// Function to insert node at any position
void insertNode(Node*& head, int position, int newValue) {
    if (position < 1) {
        std::cerr << "Invalid position\n";
        return;
    }

    // position 1 is essentially inserting at beginning
    if (position == 1) {
        insertAtBeginning(head, newValue);
        return;
    }

    Node* current{head};
    // - 2 for traversal adjustment
    // e.g. to add 3rd node, we need to reach node 2, which is 1 away from head node
    for (int i{position}; (i - 2) > 0; --i) {
        if (current->next != nullptr) { // if position is larger than list length, stay at last node
            current = current->next;
        }
    }

    // if we're at the last node, it is essentially insert at end
    if (current->next == nullptr) {
        insertNodeAtEnd(head, newValue);
        return;
    }

    // create new node
    Node* newNodePtr{new Node{}};
    newNodePtr->value = newValue;

    // link with list accounting for rest of list
    newNodePtr->next = current->next;
    current->next = newNodePtr;
}

void deleteNodeAtBeginning(Node*& head) {
    Node* tempPtr{head};
    head = head->next;
    delete tempPtr;
}

void deleteNodeAtEnd(Node* head) {
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current{head};
    // move pointer to second-to-last node
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // delete last node from the second-to-last node
    delete current->next;
    // set new last node
    current->next = nullptr;
}

void deleteNode(Node*& head, int position) {
    if (position < 1) {
        std::cerr << "Invalid position\n";
        return;
    }

    if (position == 1) {
        deleteNodeAtBeginning(head);
        return;
    }

    Node* current{head};
    // - 2 for traversal adjustment
    // e.g. to delete 3rd node, we need to reach node 2, which is 1 away from head node
    for (int i{position}; (i - 2) > 0; --i) {
        if (current->next->next != nullptr) { // if position is larger than list length, stay at second-to-last node
            current = current->next;
        }
    }

    // if we're at the second-to-last node, it is essentially remove at end
    if (current->next == nullptr) {
        deleteNodeAtEnd(head);
        return;
    }

    // remove node accounting for linking node that takes it position
    Node* tempPtr{current->next};
    current->next = current->next->next;
    delete tempPtr;
}

// Function to double all values in the list
void doubleValues(Node* head) {
    Node* current{head};

    while (current != nullptr) {
        current->value = current->value * 2;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // Allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Assign values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Set the head of the list
    head = one;

    // Print the initial list
    cout << "Original list: ";
    printList(head);

    // Insert a new node at the beginning
    insertAtBeginning(head, 0);

    // Print the updated list
    cout << "List after insertion at the beginning: ";
    printList(head);

    // Print odd numbers
    std::cout << "List but only odd numbers: ";
    printOddNumbers(head);

    // Add 4 to end of list
    insertNodeAtEnd(head, 4);
    std::cout << "List after adding 4 to the end: ";
    printList(head);

    // Double list
    doubleValues(head);
    std::cout << "Doubled list: ";
    printList(head);

    // Insert 4th element
    insertNode(head, 4, 10);
    std::cout << "List after adding 10 after the 3rd element: ";
    printList(head);

    // Remove node at beginning
    deleteNodeAtBeginning(head);
    std::cout << "List after deletion at the beginning: ";
    printList(head);

    // Remove node at end
    deleteNodeAtEnd(head);
    std::cout << "List after deletion at the end: ";
    printList(head);

    // Delete 2nd element
    deleteNode(head, 3);
    std::cout << "List after deleting 3rd element: ";
    printList(head);

    // Print list in reverse
    std::cout << "Reverse List: ";
    printListReverse(head);

    // Clean up allocated memory
    delete one;
    delete two;
    delete three;

    return 0;
}