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
void insertAtPosition(Node*& head, int position, int value);

// DELETING FUNCTIONS
void deleteAtBeginning(Node*& head);
void deleteAtEnd(Node*& head);
void deleteWithValue(Node*& head, int target);
void deleteAtPosition(Node*& head, int position);

// PRINTING FUNCTIONS
void printReverse(const Node* head);
void printOdd(const Node* head);

// MUTATING FUNCTIONS
void doubleValues(Node* head);
void swapValuePairs(Node* head);
void removeConsecutiveDuplicates(Node* head);
void removeDuplicates(Node* head);
void simpleConcatenate(Node* headA, Node* headB);
void reverseList(Node* head);
void removeEven(Node*& head);

// LIST OPERATION FUNCTIONS
Node* concatenate(const Node* headA, const Node* headB);
Node* deepCopy(const Node* head);

int main()
{
    Node* listHead{nullptr};
    for (int i{2}; i <= 6; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "List:";
    printList(listHead);

    removeEven(listHead);
    std::cout << "List:";
    printList(listHead);

    deleteList(listHead);

    return 0;
}

// BASIC FUNCTIONS

void printList(const Node* head) {
    // empty list
    if (head == nullptr) {
        std::cout << " [empty]\n";
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

void insertAtPosition(Node*& head, int position, int value) {
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

    // insert @ beginning
    if (position <= 1) {
        newPtr->next = head;
        head->prev = newPtr;
        head = newPtr;
        return;
    }

    // e.g. for position 2 you need to go to the 1st node or 0 traversals
    int traversals{position - 2};
    Node* currentPtr{head};
    for (int i{0}; i < traversals; ++i) {
        // keep pointer at last node if traversals overflow list
        if (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
    }

    // insert @ end
    if (currentPtr->next == nullptr) {
        currentPtr->next = newPtr;
        newPtr->prev = currentPtr;
        return;
    }

    // link node that goes after new node
    newPtr->next = currentPtr->next;
    currentPtr->next->prev = newPtr;
    // link node that goes before new node
    newPtr->prev = currentPtr;
    currentPtr->next = newPtr;
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
        std::cout << "Error: Empty list.\n";
        return;
    }

    // list has only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // currentPtr points to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    currentPtr->prev->next = nullptr;
    delete currentPtr;
}

void deleteWithValue(Node*& head, int target) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: Empty list.\n";
        return;
    }

    // target is first node in list
    if (head->data == target) {
        Node* tempPtr{head};
        head = head->next;
        head->prev = nullptr;
        delete tempPtr;
        return;
    }

    // currentPtr points to node with target value
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
        currentPtr->prev->next = nullptr;
        delete currentPtr;
        return;
    }

    // delete node and link with rest of list
    currentPtr->prev->next = currentPtr->next;
    delete currentPtr;
}

void deleteAtPosition(Node*& head, int position) {
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

    // delete @ beginning
    if (position <= 1) {
        Node* tempPtr{head};
        head = head->next;
        head->prev = nullptr;
        delete tempPtr;
        return;
    }

    // for doubly-linked lists, we can have a pointer to the node to delete
    int traversals{position - 1};
    Node* currentPtr{head};
    for (int i{0}; i < traversals; ++i) {
        // keep at last node if traversals would overflow
        if (currentPtr->next != nullptr) {
            currentPtr = currentPtr->next;
        }
    }

    // delete @ end
    if (currentPtr->next == nullptr) {
        Node* tempPtr{currentPtr};
        currentPtr->prev->next = nullptr;
        delete tempPtr;
        return;
    }

    // link nodes on each side of deleted node
    currentPtr->prev->next = currentPtr->next;
    currentPtr->next->prev = currentPtr->prev;

    // delete node
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
        std::cout << "[empty]\n";
        return;
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
    Node* swapPtrA{head};
    Node* swapPtrB{head->next};
    while (swapPtrA != nullptr && swapPtrB != nullptr) {
        int temp{swapPtrA->data};
        swapPtrA->data = swapPtrB->data;
        swapPtrB->data = temp;

        // move pointer safely
        swapPtrA = swapPtrB->next;
        swapPtrB = swapPtrA != nullptr ? swapPtrA->next : nullptr;
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
                comparePtrA->next = nullptr;
                delete comparePtrB;
                return;
            }

            // delete duplicate and link rest of list
            Node* tempPtr{comparePtrB};
            comparePtrA->next = comparePtrB->next;
            comparePtrB->next->prev = comparePtrA;

            // move pointer safely
            comparePtrB = comparePtrB->next;

            delete tempPtr;
        } else {
            // move pointers safely
            comparePtrA = comparePtrB;
            comparePtrB = comparePtrB->next;
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
                // link previous node to deleted node's next
                comparePtrB->prev->next = comparePtrB->next;
                // if there is a node after, link that to deleted node's prev
                if (comparePtrB->next != nullptr) {
                    comparePtrB->next->prev = comparePtrB->prev;
                }
                // move pointer safely before deleting
                comparePtrB = comparePtrB->next;
                // delete node
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

void reverseList(Node* head) {
    // empty list or list with one node
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* swapPtrA{head};
    Node* swapPtrB{head};
    int length{1};

    // move one pointer to the last node
    while (swapPtrB->next != nullptr) {
        swapPtrB = swapPtrB->next;
        // get length at the same time
        ++length;
    }

    int iterations{length / 2};
    for (int i{0}; i < iterations; ++i) {
        int temp{swapPtrA->data};
        swapPtrA->data = swapPtrB->data;
        swapPtrB->data = temp;

        // move pointer at the beginning forward
        swapPtrA = swapPtrA->next;
        // move pointer at the end backward
        swapPtrB = swapPtrB->prev;
    }
}

void removeEven(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: Empty list.\n";
        return;
    }

    // create a dummy pointer for proper looping and reassigning head
    Node* dummyPtr{new Node()};
    dummyPtr->next = head;

    // check node ahead for condition, deleting it or traversing pointer
    // currentPtr will always point to a node with a non-even value
    Node* currentPtr{dummyPtr};
    while (currentPtr->next != nullptr) {
        if (currentPtr->next->data % 2 == 0) {
            Node* tempPtr{currentPtr->next};
            currentPtr->next = currentPtr->next->next;
            delete tempPtr;
        } else {
            currentPtr = currentPtr->next;
        }
    }

    // important: when all is done set head properly
    head = dummyPtr->next;
}

// LIST OPERATION FUNCTIONS

Node* concatenate(const Node* headA, const Node* headB) {
    // create a new list
    Node* newHead{nullptr};

    // create nodes from list A
    while (headA != nullptr) {
        insertAtEnd(newHead, headA->data);
        headA = headA->next;
    }

    // create nodes from list B
    while (headB != nullptr) {
        insertAtEnd(newHead, headB->data);
        headB = headB->next;
    }

    return newHead;
}

Node* deepCopy(const Node* head) {
    Node* newHead{nullptr};

    while (head != nullptr) {
        insertAtEnd(newHead, head->data);
        head = head->next;
    }

    return newHead;
}