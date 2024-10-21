#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

void findNode(Node* root, int value, Node*& nodePtr, Node*& parentPtr);
void insertNode(Node*& root, int value);

void deleteFromTree(Node*& root, int value);
void deleteNode(Node*& nodeToDelete);

int main()
{
    Node* root{nullptr};

    int array[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int i : array) {
        insertNode(root, i);
    }

    deleteFromTree(root, 8);

    return 0;
}

void findNode(Node* root, int value, Node*& nodePtr, Node*& parentPtr) {
    nodePtr = root;
    parentPtr = nullptr;

    while (nodePtr != nullptr) {
        if (nodePtr->data == value) {
            return;
        }

        parentPtr = nodePtr;
        if (value < nodePtr->data) {
            nodePtr = nodePtr->left;
        } else {
            nodePtr = nodePtr->right;
        }
    }
}

void insertNode(Node*& root, int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->left = nullptr;
    newPtr->right = nullptr;

    Node* nodePtr{nullptr};
    Node* parentPtr{nullptr};
    findNode(root, value, nodePtr, parentPtr);

    // for empty tree both will be nullptr
    if (parentPtr == nullptr && nodePtr == nullptr) {
        root = newPtr;
        return;
    }

    if (value < parentPtr->data) {
        parentPtr->left = newPtr;
    } else {
        // if parentPtr->data is equal to value, default to adding Node to the right
        parentPtr->right = newPtr;
    }
}

void deleteFromTree(Node*& root, int value) {
    Node* nodePtr{nullptr};
    Node* parentPtr{nullptr};
    findNode(root, value, nodePtr, parentPtr);

    if (nodePtr == nullptr) {
        std::cout << "No node with that value.\n";
        return;
    }

    if (nodePtr == root) {
        deleteNode(root);
        return;
    }

    // must pass in the actual pointer in the tree, not nodePtr which is external
    if (nodePtr == parentPtr->left) {
        deleteNode(parentPtr->left);
    } else {
        deleteNode(parentPtr->right);
    }
}

void getInorderPredecessor(Node* node, Node*& predecessor, Node*& predecessorParent) {
    predecessorParent = node;
    predecessor = node->left;
    while (predecessor->right != nullptr) {
        predecessorParent = predecessor;
        predecessor = predecessor->right;
    }
}

void deleteNode(Node*& nodeToDelete) {
    Node* tempPtr = nodeToDelete;

    // case 1: node to be deleted has no children or one child
    if (nodeToDelete->left == nullptr) {
        nodeToDelete = nodeToDelete->right;
        delete tempPtr;
    } else if (nodeToDelete->right == nullptr) {
        nodeToDelete = nodeToDelete->left;
        delete tempPtr;
    }
    // case 2: node to be deleted has two children
    else {
        // find the inorder predecessor
        Node* predecessorParent{nullptr};
        Node* predecessor{nullptr};
        getInorderPredecessor(nodeToDelete, predecessor, predecessorParent);

        // copy the predecessor's data to the current node
        nodeToDelete->data = predecessor->data;

        // delete the predecessor

        // this is the case where the predecessor is a direct child of the node to be deleted
        // in this case we do predecessorParent->left
        if (predecessorParent == nodeToDelete) {
            // predecessor->right will always be nullptr but there may be a predecessor->left that isn't nullptr
            predecessorParent->left = predecessor->left;
        } else {
            // where predecessor is not a direct child, we must do predecessorParent->right
            // predecessor->right will always be nullptr but there may be a predecessor->left that isn't nullptr
            predecessorParent->right = predecessor->left;
        }

        delete predecessor;
    }
}
