#include <iostream>

class Node {
public:
    int data;
    Node* left{nullptr};
    Node* right{nullptr};
    Node(int value) : data(value) {}
};

// the question asks for specific node's value, so we should check if that node exists
Node* searchNode(Node* root, int value);
// recursive function that prints lesser values
void outputLesserValues(Node* root, int value);
// wrapper function that combines the two above
void displayLesserValues(Node* root, int value);

int main()
{
    // build initial BST from question 3
    Node* root{new Node(50)};
    // left subtree
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    // right subtree
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // expected output: 20 30 40 50 60
    displayLesserValues(root, 70); // change parameter to test

    return 0;
}

Node* searchNode(Node* root, int value) {
    if (!root) {
        return nullptr;
    }

    while (root && root->data != value) {
        if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

void outputLesserValues(Node* root, int value) {
    // base case
    if (!root) {
        return;
    }

    // output inorder
    outputLesserValues(root->left, value);
    if (root->data < value) {
        std::cout << ' ' << root->data;
    }
    outputLesserValues(root->right, value);
}

void displayLesserValues(Node* root, int value) {
    // show error if Node with given value does not exist in BST
    Node* nodeWithValue{searchNode(root, value)};
    if (!nodeWithValue) {
        std::cout << "Error: there is no node in BST with value " << value << '\n';
        return;
    }

    // display lesser values if node with given value exists in BST

    std::cout << "Values in BST less than " << value << ":";
    outputLesserValues(root, value);
    std::cout << '\n';
}
