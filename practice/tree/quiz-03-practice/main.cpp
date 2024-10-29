#include <iostream>

class Node {
public:
    char data;
    Node* left{nullptr};
    Node* right{nullptr};
    Node(char value) : data(value) {};
};

void insertNode(Node*& root, char value) {
    if (!root) {
        Node* newPtr{new Node(value)};
        root = newPtr;
        return;
    }

    if (value < root->data) {
        insertNode(root->left, value);
    } else if (value > root->data) {
        insertNode(root->right, value);
    } else {
        std::cout << "Node with that value already exists in BST.\n";
    }
}

void printTree(Node* root, int traversal) {
    if (!root) {
        return;
    }

    switch (traversal) {
    case 1: // inorder
        printTree(root->left, traversal);
        std::cout << ' ' << root->data;
        printTree(root->right, traversal);
        break;
    case 2: // preorder
        std::cout << ' ' << root->data;
        printTree(root->left, traversal);
        printTree(root->right, traversal);
        break;
    case 3: // postorder
        printTree(root->left, traversal);
        printTree(root->right, traversal);
        std::cout << ' ' << root->data;
        break;
    default:
        std::cout << "Invalid traversal option.\n";
    }
}

Node* searchNode(Node* root, char value) {
    if (!root) {
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
    if (!root) {
        return nullptr;
    }

    if (root->right == nullptr) {
        return root;
    }

    return getInorderPredecessor(root->right);
}

void deleteNode(Node*& root);
void deleteFromTree(Node*& root, char value);

int main() {
    Node* root{nullptr};
    insertNode(root, 'E');
    insertNode(root, 'C');
    insertNode(root, 'H');
    insertNode(root, 'A');
    insertNode(root, 'D');
    insertNode(root, 'F');
    insertNode(root, 'I');
    insertNode(root, 'B');
    insertNode(root, 'G');
    insertNode(root, 'J');

    deleteFromTree(root, 'H');

    std::cout << "Inorder Tree:";
    printTree(root, 1);
    std::cout << '\n';

    std::cout << "Preorder Tree:";
    printTree(root, 2);
    std::cout << '\n';

    std::cout << "Postorder Tree:";
    printTree(root, 3);
    std::cout << '\n';

    return 0;
}

void deleteNode(Node*& root) {
    Node* tempPtr{root};

    // the first two conditions handles both node with no children and node with one child
    if (root->left == nullptr) {
        root = root->right;
        delete tempPtr;
    } else if (root->right == nullptr) {
        root = root->left;
        delete tempPtr;
    } else {
        // case where node with two children
        // 1) get the logical or inorder predecessor/successor
        // 2) assign node to delete the value of the predecessor/successor node
        // 3) delete the predecessor/successor node by passing the respective subtree of the original node to delete
        int logicalPredecessorValue{getInorderPredecessor(root->left)->data};
        root->data = logicalPredecessorValue;
        deleteFromTree(root->left, logicalPredecessorValue);
    }
}

void deleteFromTree(Node*& root, char value) {
    if (root == nullptr) {
        return;
    }

    if (value < root->data) {
        deleteFromTree(root->left, value);
    } else if (value > root->data) {
        deleteFromTree(root->right, value);
    } else {
        deleteNode(root);
    }
}
