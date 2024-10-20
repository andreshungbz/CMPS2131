#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

void insertNode(Node*& root, int value);
void printTree(Node* root, int traversal);
int treeNodeCount(Node* root);
int treeHeight(Node* root);
Node* retrieveNode(Node*& root, int value);
Node* retrieveParentNode(Node* root, int value);

Node* getInorderPredecessor(Node* subtree);
void deleteNode(Node*& root);
void deleteFromTree(Node*& root, int value);


int main() {
    std::cout << std::boolalpha;

    Node* root{nullptr};

    int array[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int i : array) {
        insertNode(root, i);
    }

    std::cout << "Tree:";
    printTree(root, 1);
    std::cout << '\n';

    std::cout << "Tree Node Count: " << treeNodeCount(root) << '\n';

    std::cout << "10 exists in tree: " << static_cast<bool>(retrieveNode(root, 10)) << '\n';
    std::cout << "16 exists in tree: " << static_cast<bool>(retrieveNode(root, 16)) << '\n';

    deleteFromTree(root, 4);

    std::cout << "Tree after delete 4:";
    printTree(root, 1);
    std::cout << '\n';

    return 0;
}

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

void printTree(Node* root, int traversal) {
    if (root == nullptr) {
        return;
    }

    switch (traversal) {
        // 1 for inorder traversal
    case 1:
        printTree(root->left, 1);
        std::cout << ' ' << root->data;
        printTree(root->right, 1);
        break;
        // 2 for postorder traversal
    case 2:
        printTree(root->left, 2);
        printTree(root->right, 2);
        std::cout << ' ' << root->data;
        break;
        // 3 for preorder traversal
    case 3:
        std::cout << ' ' << root->data;
        printTree(root->left, 3);
        printTree(root->right, 3);
        break;
    default:
        std::cout << "invalid traversal option";
    };
}

int treeNodeCount(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return treeNodeCount(root->left) + treeNodeCount(root->right) + 1;
}

int treeHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* retrieveNode(Node*& root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == value) {
        return root;
    } else if (value < root->data) {
        return retrieveNode(root->left, value);
    } else {
        return retrieveNode(root->right, value);
    }
}

Node* retrieveParentNode(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return nullptr;
    }

    if ((root->left != nullptr && root->left->data == value) ||
        (root->right != nullptr && root->right->data == value)) {
        return root;
    }

    if (value < root->data) {
        return retrieveParentNode(root->left, value);
    } else {
        return retrieveParentNode(root->right, value);
    }
}

Node* getInorderPredecessor(Node* subtree) {
    while (subtree != nullptr && subtree->right != nullptr) {
        subtree = subtree->right;
    }

    return subtree;
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

void deleteFromTree(Node*& root, int value) {
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