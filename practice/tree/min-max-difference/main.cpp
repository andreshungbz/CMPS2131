#include <iostream>

class Node {
public:
    int data{0};
    Node* left{nullptr};
    Node* right{nullptr};

    // constructor
    Node(int value) : data(value) {}
};

int findSmallestValue(Node* root);
int findSmallestValueRecursive(Node* root);
int findLargestValue(Node* root);
int findLargestValueRecursive(Node* root);
int differenceSmallestLargest(Node* root);

int main() {
    Node* root{new Node(8)};
    root->left = new Node(7);
    root->right = new Node(9);

    // 2 expected
    std::cout << "difference of largest and smallest: " << differenceSmallestLargest(root) << '\n';
    return 0;
}

int findSmallestValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    // the smallest value will always be the leftmost node in a BST
    Node* currentPtr{root};
    while (currentPtr->left != nullptr) {
        currentPtr = currentPtr->left;
    }

    return currentPtr->data;
}

int findSmallestValueRecursive(Node* root) {
    // empty tree check
    if (root == nullptr) {
        return -1;
    }

    // base case where no more on the left
    if (!root->left) {
        return root->data;
    }

    // keep going left if root->left has more
    return findSmallestValueRecursive(root->left);
}

int findLargestValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    // the largest value will always be the rightmost node in a BST
    Node* currentPtr{root};
    while (currentPtr->right != nullptr) {
        currentPtr = currentPtr->right;
    }

    return currentPtr->data;
}

int findLargestValueRecursive(Node* root) {
    // empty tree check
    if (root == nullptr) {
        return -1;
    }

    // base case where no more on the right
    if (!root->right) {
        return root->data;
    }

    // keep going right if root->right has more
    return findLargestValueRecursive(root->right);
}

int differenceSmallestLargest(Node* root) {
    int smallest = findSmallestValueRecursive(root);
    int largest = findLargestValueRecursive(root);

    // ASSUMPTION: we are only working with positive node values and anything negative is invalid
    if (smallest == -1 || largest == -1) {
        return -1;
    }

    return largest - smallest;
}