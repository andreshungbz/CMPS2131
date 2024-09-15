// Doubly-linked List

#include <iostream>

// Node for doubly-linked list
class Node {
public:
    Node* prev;
    int data;
    Node* next;
};

// BASIC FUNCTIONS
void printList(const Node* head);
void deleteList(Node*& head);

// INSERTING FUNCTIONS
void insertAtBeginning(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void insertAfterValue(Node*& head, int target, int value);

// DELETING FUNCTIONS
void deleteAtBeginning(Node*& head);
void deleteAtEnd(Node*& head);
void deleteWithValue(Node*& head, int target);

// PRINTING FUNCTIONS
void printReverse(const Node* head);
void printOdd(const Node* head);

// MUTATING FUNCTIONS
void doubleValues(Node* head);
void swapValuePairs(Node* head);
void removeConsecutiveDuplicates(Node* head);
void removeDuplicates(Node* head);
void simpleConcatenate(Node* headA, Node* headB);
void reverse(Node* head);

// LIST OPERATION FUNCTIONS
Node* concatenate(const Node* headA, const Node* headB);
Node* deepCopy(const Node* head);

int main()
{
    Node* listHead{nullptr};
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    printList(listHead);

    insertAfterValue(listHead, 5, 9);
    std::cout << "List:";
    printList(listHead);

    deleteList(listHead);
    return 0;
}

// BASIC FUNCTIONS

void printList(const Node* head) {
    // empty list
    if (head == nullptr) {
        std::cout << "[empty]\n";
        return;
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
}

// INSERTING FUNCTIONS

void insertAtBeginning(Node*& head, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->next = nullptr;
    newPtr->data = value;
    newPtr->prev = nullptr;

    // empty list
    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // link nodes
    newPtr->next = head;
    head->prev = newPtr;
    head = newPtr;
}

void insertAtEnd(Node*& head, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->prev = nullptr;
    newPtr->data = value;
    newPtr->next = nullptr;

    // empty list
    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // create pointer that points to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // insert node at the end and link next and prev
    newPtr->prev = currentPtr;
    currentPtr->next = newPtr;
}

void insertAfterValue(Node*& head, int target, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->prev = nullptr;
    newPtr->data = value;
    newPtr->next = nullptr;

    // empty list
    if (head == nullptr) {
        std::cout << "Error: Target not found.\n";
        return;
    }

    // create a pointer to the node with target value
    Node* currentPtr{head};
    while (currentPtr != nullptr && currentPtr->data != target) {
        currentPtr = currentPtr->next;
    }

    // no target value found
    if (currentPtr == nullptr) {
        std::cout << "Error: Target not found.\n";
        return;
    }

    // target node is @ end of list
    if (currentPtr->next == nullptr) {
        currentPtr->next = newPtr;
        newPtr->prev = currentPtr;
        return;
    }

    // link node that goes after new node
    newPtr->next = currentPtr->next;
    currentPtr->next->prev = newPtr;
    // link node that goes before new node
    currentPtr->next = newPtr;
    newPtr->prev = currentPtr;
}

// DELETING FUNCTIONS

void deleteAtBeginning(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: Empty list.\n";
        return;
    }

    // list has only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // delete node @ beginning
    Node* tempPtr{head};
    head = head->next;
    head->prev = nullptr;
    delete tempPtr;
}

void deleteAtEnd(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error Deleting: Empty list.\n";
        return;
    }

    // list has only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // delete node @ end
    Node* currentPtr{head};
    // currentPtr points to the last node
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->prev->next = nullptr;
    delete currentPtr;
}

void deleteWithValue(Node*& head, int target) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error Deleting: Empty list.\n";
        return;
    }

    // target is first node in list
    if (head->data == target) {
        deleteAtBeginning(head);
        return;
    }

    // currentPtr points to node with target value
    Node* currentPtr{head};
    while (currentPtr != nullptr && currentPtr->data != target) {
        currentPtr = currentPtr->next;
    }

    // no target value found
    if (currentPtr == nullptr) {
        std::cout << "Error Deleting: No target value found.\n";
        return;
    }

    // target node is @ end of list
    if (currentPtr->next == nullptr) {
        deleteAtEnd(head);
        return;
    }

    // delete node and link with rest of list
    currentPtr->prev->next = currentPtr->next;
    delete currentPtr;
}

// PRINTING FUNCTIONS

void printReverse(const Node* head) {
    if (head == nullptr) {
        return;
    }

    printReverse(head->next);
    std::cout << ' ' << head->data;
}

void printOdd(const Node* head) {
    if (head == nullptr) {
        std::cout << "[Empty list]";
    }

    while (head != nullptr) {
        if (head->data % 2 != 0) {
            std::cout << ' ' << head->data;
        }

        head = head->next;
    }

    std::cout << '\n';
}

// MUTATING FUNCTIONS

void doubleValues(Node* head) {
    if (head == nullptr) {
        return;
    }

    // double every node's data value
    while (head != nullptr) {
        head->data = head->data * 2;
        head = head->next;
    }
}

void swapValuePairs(Node* head) {
    // empty list or only one node in list
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // swap the data values of each pair of nodes
    while (head != nullptr && head->next != nullptr) {
        int temp{head->data};
        head->data = head->next->data;
        head->next->data = temp;

        // move pointer safely
        head = head->next != nullptr && head->next->next != nullptr ? head->next->next : nullptr;
    }
}

void removeConsecutiveDuplicates(Node* head) {
    // empty list or only one node in list
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* comparePtrA{head};
    Node* comparePtrB{head->next};
    while (comparePtrB != nullptr) {
        if (comparePtrA->data == comparePtrB->data) {
            // the duplicate is at the end of the list
            if (comparePtrB->next == nullptr) {
                deleteAtEnd(head);
                return;
            }

            // delete duplicate and link rest of list
            Node* tempPtr{comparePtrB};
            comparePtrA->next = comparePtrB->next;
            comparePtrB->next->prev = comparePtrA;
            comparePtrB = comparePtrB->next;
            delete tempPtr;
        } else {
            // move pointers safely
            comparePtrA = comparePtrB;
            comparePtrB = comparePtrA->next;
        }
    }
}

void removeDuplicates(Node* head) {
    // empty list or only one node in list
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* comparePtrA{head};
    while (comparePtrA != nullptr) {
        Node* comparePtrB{comparePtrA->next};
        while (comparePtrB != nullptr) {
            // duplicate found
            if (comparePtrB->data == comparePtrA->data) {
                // delete duplicate and link rest of list
                Node* tempPtr{comparePtrB};
                comparePtrB->prev->next = comparePtrB->next;
                if (comparePtrB->next != nullptr) {
                    comparePtrB->next->prev = comparePtrB->prev;
                }
                comparePtrB = comparePtrB->next;
                delete tempPtr;
            } else {
                comparePtrB = comparePtrB->next;
            }
        }

        comparePtrA = comparePtrA->next;
    }
}

void simpleConcatenate(Node* headA, Node* headB) {
    // empty lists
    if (headA == nullptr || headB == nullptr) {
        return;
    }

    // move headA to point to the last node in list A
    while (headA->next != nullptr) {
        headA = headA->next;
    }

    // concatenate
    headA->next = headB;
    headB->prev = headA;
}

void reverse(Node* head) {
    // empty list or list with one node
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* swapPtrA{head};
    Node* swapPtrB{head};
    int length{1};

    while (swapPtrB->next != nullptr) {
        swapPtrB = swapPtrB->next;
        ++length;
    }

    int counter{length / 2};
    for (int i{0}; i < counter; ++i) {
        int temp{swapPtrA->data};
        swapPtrA->data = swapPtrB->data;
        swapPtrB->data = temp;

        swapPtrA = swapPtrA->next;
        swapPtrB = swapPtrB->prev;
    }
}

// LIST OPERATION FUNCTIONS

Node* concatenate(const Node* headA, const Node* headB) {
    // create a new list
    Node* head{nullptr};

    // create nodes from list A
    while (headA != nullptr) {
        insertAtEnd(head, headA->data);
        headA = headA->next;
    }

    // create nodes from list B
    while (headB != nullptr) {
        insertAtEnd(head, headB->data);
        headB = headB->next;
    }

    return head;
}

Node* deepCopy(const Node* head) {
    Node* newHead{nullptr};

    while (head != nullptr) {
        insertAtEnd(newHead, head->data);
        head = head->next;
    }

    return newHead;
}