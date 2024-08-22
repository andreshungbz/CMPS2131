#include <iostream>
using namespace std;

// Creating a node
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

// Function to insert node after node 3
void insert4thNode(Node* head, int newValue) {
    Node* current{head};

    // set pointer to the 3rd node
    // needs to traverse 2 times from node 1 (NODE1 -> NODE2 -> NODE3)
    int traverseCounter{2};
    while (traverseCounter) {
        current = current->next;

        if (current == nullptr) {
            std::cout << "List not long enough. Exiting.\n";
            return;
        }

        --traverseCounter;
    }

    // create new node
    Node* newNodePtr{new Node{}};
    newNodePtr->value = newValue;
    newNodePtr->next = nullptr;

    // list conveniently only has three items
    if (current->next == nullptr) {
        current->next = newNodePtr;
    } else { // the new node needs to point to the old 4th element
        newNodePtr->next = current->next;
        current->next = newNodePtr;
    }
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

    // Insert after the 3rd element
    insert4thNode(head, 10);
    std::cout << "List after adding 10 after the 3rd element: ";
    printList(head);

    // Clean up allocated memory
    delete one;
    delete two;
    delete three;

    return 0;
}