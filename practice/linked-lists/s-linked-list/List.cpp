// List class implementation

#include "List.h"

List::List() {
    head = nullptr;
    tail = nullptr;
}

void List::createNode(int value) {
    Node* temp = new Node; // create temporary Node

    // temp->data is equivalent to (*temp).data
    temp->data = value; // set new value into temp
    temp->next = nullptr; // temp is the new last element, so its next points to nullptr

    if (head == nullptr) { // if the list is empty, set both to temp
        head = temp;
        tail = temp;
    } else { // if an item already exists in the list
        tail->next = temp; // have the list's current last element point to the new element temp
        tail = temp; // set the list's new last element to temp
    }
}

void List::display() const {
    Node* temp = head; // use temp to traverse the list starting at head

    while (temp != nullptr) {
        std::cout << temp->data << '\t'; // show the data of the current Node
        temp = temp->next; // move to the next Node
    }
}
