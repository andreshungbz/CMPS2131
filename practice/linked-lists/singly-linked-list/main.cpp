// Singly-linked List

#include <iostream>

// Node for singly-linked list
class Node {
public:
    int data;
    Node* next;
};

// BASIC FUNCTIONS
void printList(const Node* head);
void deleteList(Node*& head);

// INSERTING FUNCTIONS
void insertAtBeginning(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void insertAfterValue(Node*& head, int target, int value); // only after first instance of target

// DELETING FUNCTIONS
void deleteAtBeginning(Node*& head);
void deleteAtEnd(Node*& head);
void deleteWithValue(Node*& head, int target); // only first instance of target

// PRINTING FUNCTIONS
void printReverse(const Node* head);
void printOdd(const Node* head);

// MUTATING FUNCTIONS
void doubleValues(Node* head);
void swapValuePairs(Node* head);
void removeConsecutiveDuplicates(Node* head);
void removeDuplicates(Node* head);
void simpleConcatenate(Node* headA, Node* headB);
void reverse(Node*& head);

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

    deleteWithValue(listHead, 5);
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
    newPtr->data = value;
    newPtr->next = nullptr;

    // empty list
    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // insert node at the beginning
    newPtr->next = head;
    head = newPtr;
}

void insertAtEnd(Node*& head, int value) {
    // create new node
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    // empty list - essentially insert at beginning
    if (head == nullptr) {
        head = newPtr;
        return;
    }

    // traverse a pointer to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // insert node at the end
    currentPtr->next = newPtr;
}

void insertAfterValue(Node*& head, int target, int value) {
    // create new node
    Node* newPtr{new Node()};
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
        return;
    }

    // there are nodes after target node that need to be linked
    newPtr->next = currentPtr->next;
    currentPtr->next = newPtr;
}

// DELETING FUNCTIONS

void deleteAtBeginning(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: List is empty.\n";
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
    delete tempPtr;
}

void deleteAtEnd(Node*& head) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error: List is empty.\n";
        return;
    }

    // list has only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // logic for list with >1 node
    // traverse pointer to second-to-last node
    Node* currentPtr{head};
    while (currentPtr->next->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // delete node @ end
    Node* tempPtr{currentPtr->next};
    currentPtr->next = nullptr;
    delete tempPtr;
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
        delete tempPtr;
        return;
    }

    Node* previousPtr{head};
    Node* currentPtr{head};
    while (currentPtr != nullptr && currentPtr->data != target) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    // no target value found
    if (currentPtr == nullptr) {
        std::cout << "Error : Target not found.\n";
        return;
    }

    // target node is @ end of list
    if (currentPtr->next == nullptr) {
        // list has only one node
        if (currentPtr == previousPtr) {
            delete currentPtr;
            head = nullptr;
            return;
        }

        // delete node @ end
        previousPtr->next = nullptr;
        delete currentPtr;
        return;
    }

    // there are nodes after target node that need to be linked
    previousPtr->next = currentPtr->next;
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
        std::cout << " [empty]";
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
        Node* previousPtr{comparePtrA};
        Node* comparePtrB{comparePtrA->next};
        while (comparePtrB != nullptr) {
            // duplicate found
            if (comparePtrB->data == comparePtrA->data) {
                // delete duplicate and link rest of list
                Node* tempPtr{comparePtrB};
                previousPtr->next = comparePtrB->next;
                comparePtrB = comparePtrB->next;
                delete tempPtr;
            } else {
                // move pointers safely
                previousPtr = comparePtrB;
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
}

void reverse(Node*& head) {
    // empty list or list with one item
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* previousPtr{nullptr};
    Node* currentPtr{head};
    Node* nextPtr{nullptr};

    while (currentPtr != nullptr) {
        nextPtr = currentPtr->next;
        currentPtr->next = previousPtr;
        previousPtr = currentPtr;
        currentPtr = nextPtr;
    }

    // reassign head
    head = previousPtr;
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

    if (head == nullptr) {
        return newHead;
    }

    while (head != nullptr) {
        insertAtEnd(newHead, head->data);
        head = head->next;
    }

    return newHead;
}