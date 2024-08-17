// The List class is a singly linked list that contains a head and tail pointer.

#ifndef LIST_H
#define LIST_H

#include <iostream>

// structure of Node in the List that represents a single element in the list.
struct Node {
    int data;
    Node* next; // struct Node* is redundant, Node* is enough.
};

// the List class that uses the Node struct
class List {
public:
    List(); // default constructor
    void createNode(int value); // a method for creating a new item in the list
    void display() const; // a method for displaying all list items from beginning to end
private:
    Node* head;
    Node* tail;
};

#endif // LIST_H
