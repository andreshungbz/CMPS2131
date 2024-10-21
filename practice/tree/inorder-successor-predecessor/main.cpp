#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        Node* newPtr{new Node};
        newPtr->data = value;
        newPtr->left = nullptr;
        newPtr->right = nullptr;

        root = newPtr;
    } else if (value < root->data) {
        insertNode(root->left, value);
    } else {
        // if root->data is equal to value, default to sending Node to the right
        insertNode(root->right, value);
    }
}

Node* searchNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == value) {
        return root;
    } else if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

Node* getInorderPredecessor(Node* root) {
    while (root != nullptr && root->right != nullptr) {
        root = root->right;
    }

    return root;
}

Node* getInorderSuccessor(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }

    return root;
}

void searchInorderPredecessor(Node* root, int value) {
    Node* targetNode{searchNode(root, value)};

    if (!targetNode) {
        std::cout << "Node with value " << value << " does not exist in tree.\n";
    } else {
        Node* predecessor{getInorderPredecessor(targetNode->left)};

        if (!predecessor) {
            std::cout << "Node with " << targetNode->data << " has no predecessor\n";
        } else {
            std::cout << "Node with " << targetNode->data << " has predecessor of Node with " << predecessor->data << '\n';
        }
    }
}

void searchInorderSuccessor(Node* root, int value) {
    Node* targetNode{searchNode(root, value)};

    if (!targetNode) {
        std::cout << "Node with value " << value << " does not exist in tree.\n";
    } else {
        Node* successor{getInorderSuccessor(targetNode->right)};

        if (!successor) {
            std::cout << "Node with " << targetNode->data << " has no successor\n";
        } else {
            std::cout << "Node with " << targetNode->data << " has successor of Node with " << successor->data << '\n';
        }
    }
}

int main()
{
    Node* root{nullptr};

    int array[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int i : array) {
        insertNode(root, i);
    }

    searchInorderPredecessor(root, 4);
    searchInorderSuccessor(root, 8);

    return 0;
}
