// Code explanation

#include <cstddef> // defines the NULL macro
#include <iostream>

using namespace std; // std namespace contains all the classes, objects, and functions of the C++ Standard Library

// the Node class represents a node in a linked list
class Node {
public:
    int data;
    Node * next; // the next pointer points to the next node in the linked list
};

// this functions prints all elements in the linked list starting from the given node
void print_list(Node * n) {
    while (n != NULL) {
        cout << n->data << " "; // dereference the Node object pointer and access the Node object's data field
        n = n->next; // move to the next node in the linked list
    }
}

int main() {
    // create pointers to Node objects, initializing them to NULL
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;

    // set each pointer to point to the address of a new Node object
    head = new Node();
    second = new Node();
    third = new Node();

    // set the data field of each Node object and link them together
    // head->next is equivalent to (*head).next
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // prints 1 2 3
    print_list(head);
}
