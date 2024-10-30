#include <iostream>

class Node {
public:
    int data;
    Node* left{nullptr};
    Node* right{nullptr};
    Node(int value) : data(value) {}
};

// empty is used to distinguish between an empty tree and a tree where the largest node is root
// in both cases the returned parentPtr is nullptr
Node* findLargestNodeParent(Node* root, bool& empty);

int main()
{
    // build simple BST
    // can comment to test
    Node* root{new Node(7)}; // can initialize to nullptr for testing
    root->left = new Node(5);
    root->right = new Node(8);
    root->right->right = new Node(9);

    bool isEmpty{false};
    Node* largestNodeParentPointer{findLargestNodeParent(root, isEmpty)};

    // empty tree
    if (isEmpty) {
        std::cout << "No parent node of largest node (tree is empty).\n";
        return 0;
    }

    // largest node is root
    if (!largestNodeParentPointer && !isEmpty) {
        std::cout << "No parent node of largest node (largest node is root).\n";
        return 0;
    }

    // parentPtr is not nullptr
    // expected: parent node with value 8 of largest node which has value 9
    std::cout << "The parent node of the largest node in the tree has value: " << largestNodeParentPointer->data << '\n';

    return 0;
}

// function definition
Node* findLargestNodeParent(Node* root, bool& empty) {
    Node* parentPtr{nullptr};
    Node* currentPtr{root};

    while (currentPtr && currentPtr->right) {
        parentPtr = currentPtr;
        currentPtr = currentPtr->right;
    }

    // for an empty tree, currentPtr will be nullptr, set true in that case, else false
    empty = currentPtr == nullptr;

    return parentPtr;
}
