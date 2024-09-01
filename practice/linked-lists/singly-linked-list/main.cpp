// Singly-linked List

#include <iostream>

// Node for singly-linked list
class Node {
public:
    int data;
    Node* next;
};

// INSERTING FUNCTIONS

void insertAtBeginning(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void insertAfterValue(Node*& head, int target, int value);

// DELETING FUNCTIONS

void deleteAtBeginning(Node*& head);
void deleteAtEnd(Node*& head);
void deleteWithValue(Node*& head, int target);
void deleteList(Node*& head);

// PRINTING FUNCTIONS

void print(Node* head);
void printReverse(Node* head);
void printOdd(Node* head);

// MUTATING FUNCTIONS

void doubleValues(Node* head);
void swapValuePairs(Node* head);
void removeConsecutiveDuplicates(Node* head);
void removeDuplicates(Node* head);
void concatenate(Node* headA, Node* headB);

int main()
{
    // list
    Node* listHead{nullptr};

    // insertAtBeginning
    for (int i{1}; i <= 5; ++i) {
        insertAtBeginning(listHead, i);
    }
    std::cout << "insertAtBeginning:";
    print(listHead);

    // insertAtEnd
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "insertAtEnd:";
    print(listHead);

    // insertAfterValue

    insertAfterValue(listHead, 3, 9);
    std::cout << "Insert 9 after node w/ value 3:";
    print(listHead);

    std::cout << "Insert 9 after node w/ value 10: ";
    insertAfterValue(listHead, 10, 9);

    deleteList(listHead);
    std::cout << "Cleared List: ";
    print(listHead);

    std::cout << "Insert 9 after node w/ value 10: ";
    insertAfterValue(listHead, 10, 9);

    // printReverse
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "Initial List:";
    print(listHead);
    std::cout << "List printed in reverse:";
    printReverse(listHead);

    // printOdd
    std::cout << "\nOdd numbers:";
    printOdd(listHead);

    // deleteAtBeginning
    std::cout << "deleteAtBeginning:";
    deleteAtBeginning(listHead);
    print(listHead);

    // deleteAtEnd
    std::cout << "deleteAtEnd:";
    deleteAtEnd(listHead);
    print(listHead);

    // deleteWithValue
    std::cout << "Delete first node with value 3:";
    deleteWithValue(listHead, 2);
    print(listHead);

    // doubleValues
    std::cout << "Double every value:";
    doubleValues(listHead);
    print(listHead);

    // clear list
    deleteList(listHead);
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
    }
    std::cout << "New List:";
    print(listHead);

    // swapValuePairs
    std::cout << "List after value pair swap:";
    swapValuePairs(listHead);
    print(listHead);

    // clear list
    deleteList(listHead);
    for (int i{1}; i <= 5; ++i) {
        insertAtEnd(listHead, i);
        insertAtEnd(listHead, i);
    }
    deleteWithValue(listHead, 3);
    deleteWithValue(listHead, 5);
    std::cout << "New List:";
    print(listHead);

    // removeConsecutiveDuplicates
    std::cout << "List with removed consecutive duplicates:";
    removeConsecutiveDuplicates(listHead);
    print(listHead);

    // add duplicates
    for (int i{1}; i <= 5; ++i) {
        insertAtBeginning(listHead, i);
    }
    std::cout << "List:";
    print(listHead);

    // removeDuplicates
    std::cout << "List with removed duplicates:";
    removeDuplicates(listHead);
    print(listHead);

    // create another list
    Node* listHead2{nullptr};
    for (int i{1}; i <= 5; ++i) {
        insertAtBeginning(listHead2, 5);
    }
    std::cout << "Another list:";
    print(listHead2);

    // concatenate
    std::cout << "Concatenated list:";
    concatenate(listHead, listHead2);
    print(listHead);

    deleteList(listHead);
    return 0;
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
    // empty list
    if (head == nullptr) {
        insertAtBeginning(head, value);
        return;
    }

    // create new node
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    // create a pointer to the last node
    Node* currentPtr{head};
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }

    // insert node at the end
    currentPtr->next = newPtr;
}

void insertAfterValue(Node*& head, int target, int value) {
    // empty list
    if (head == nullptr) {
        std::cout << "Error Inserting: No target value found.\n";
        return;
    }

    // create a pointer to the node with target value
    Node* currentPtr{head};
    while (currentPtr != nullptr && currentPtr->data != target) {
        currentPtr = currentPtr->next;
    }

    // no target value found
    if (currentPtr == nullptr) {
        std::cout << "Error Inserting: No target value found.\n";
        return;
    }

    // target node is @ end of list
    if (currentPtr->next == nullptr) {
        insertAtEnd(head, value);
        return;
    }

    // create new node
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    // insert node and link rest of list
    newPtr->next = currentPtr->next;
    currentPtr->next = newPtr;
}

// DELETING FUNCTIONS

void deleteAtBeginning(Node*& head) {
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

    // delete node @ beginning
    Node* tempPtr{head};
    head = head->next;
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
    Node* previousPtr{head};
    Node* currentPtr{head};

    // currentPtr points to the last node
    // previousPtr points to the second-to-last node
    while (currentPtr->next != nullptr) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    previousPtr->next = nullptr;
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
    // previousPtr points to node before currentPtr
    Node* previousPtr{head};
    Node* currentPtr{head};
    while (currentPtr != nullptr && currentPtr->data != target) {
        previousPtr = currentPtr;
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
    previousPtr->next = currentPtr->next;
    delete currentPtr;
}

void deleteList(Node*& head) {
    // empty list
    if (head == nullptr) {
        return;
    }

    // traverse through the list, deleting every node using a temporary pointer
    Node* currentPtr{head};
    while (currentPtr != nullptr) {
        Node* tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        delete tempPtr;
    }

    // reset original list
    head = nullptr;
}

// PRINTING FUNCTIONS

void print(Node* head) {
    if (head == nullptr) {
        std::cout << "[Empty list]";
    }

    while (head != nullptr) {
        std::cout << ' ' << head->data;
        head = head->next;
    }

    std::cout << '\n';
}

void printReverse(Node* head) {
    if (head == nullptr) {
        return;
    }

    printReverse(head->next);
    std::cout << ' ' << head->data;
}

void printOdd(Node* head) {
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
    Node* swapPtrA{head};
    Node* swapPtrB{head->next};
    while (swapPtrB != nullptr) {
        int temp{swapPtrA->data};
        swapPtrA->data = swapPtrB->data;
        swapPtrB->data = temp;

        // move pointers safely
        swapPtrA = swapPtrB->next;
        swapPtrB = swapPtrA->next != nullptr ? swapPtrA->next : nullptr;
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

void concatenate(Node* headA, Node* headB) {
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