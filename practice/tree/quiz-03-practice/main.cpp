#include <iostream>

class CharNode {
public:
    char data;
    CharNode* left{nullptr};
    CharNode* right{nullptr};
    CharNode(char value) : data(value) {};
};

void insertNode(CharNode*& root, char value);
void printTree(CharNode* root, int traversal);
CharNode* searchNode(CharNode* root, char value);
CharNode* getInorderPredecessor(CharNode* root);
CharNode* getInorderSuccessor(CharNode* root);
void deleteNode(CharNode*& root);
void deleteFromTree(CharNode*& root, char value);

class IntNode {
public:
    int data;
    IntNode* left{nullptr};
    IntNode* right{nullptr};
    IntNode(int value) : data(value) {};
};

int countOddRecursive(IntNode* root) {
    if (!root) {
        return 0;
    }

    int oddCount{0};
    if (root->data % 2 == 1) {
        oddCount = 1;
    }

    int oddCountLeft = countOddRecursive(root->left);
    int oddCountRight = countOddRecursive(root->right);

    return oddCount + oddCountLeft + oddCountRight;
}

void countEvenTraverse(IntNode* root, int& result) {
    if (!root) {
        return;
    }

    if (root->data % 2 == 0) {
        ++result;
    }
    countEvenTraverse(root->left, result);
    countEvenTraverse(root->right, result);
}

int treeHeight(IntNode* root) {
    if (!root) {
        return -1;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    int largerHeight{leftHeight > rightHeight ? leftHeight : rightHeight};

    return largerHeight + 1;
}

bool isBST(IntNode* root, int min, int max) {
    if (!root) {
        return true;
    }

    if (root->data <= min || root->data >= max) {
        return false;
    }

    bool leftIsBST{isBST(root->left, min, root->data)};
    bool rightIsBST{isBST(root->right, root->data, max)};

    return leftIsBST && rightIsBST;
}

bool isFullBinaryTree(IntNode* root) {
    if (!root) {
        return true;
    }

    bool isFull{true};
    if ((!root->left && root->right) || (!root->right && root->left)) {
        isFull = false;
    }

    bool leftIsFull{isFullBinaryTree(root->left)};
    bool rightIsFull{isFullBinaryTree(root->right)};

    return isFull && leftIsFull && rightIsFull;
}

int doubleParentCountRecursive(IntNode* root) {
    if (!root) {
        return 0;
    }

    int count{0};
    if (root->left && root->right) {
        count = 1;
    }

    int countLeft{doubleParentCountRecursive(root->left)};
    int countRight{doubleParentCountRecursive(root->right)};

    return count + countLeft + countRight;
}

void doubleParentCountTraverse(IntNode* root, int& result) {
    if (!root) {
        return;
    }

    if (root->left && root->right) {
        ++result;
    }

    doubleParentCountTraverse(root->left, result);
    doubleParentCountTraverse(root->right, result);
}

int sumTreeValuesRecursive(IntNode* root) {
    if (!root) {
        return 0;
    }

    int sumLeftTree = sumTreeValuesRecursive(root->left);
    int sumRightTree = sumTreeValuesRecursive(root->right);

    return root->data + sumLeftTree + sumRightTree;
}

void sumTreeValuesTraverse(IntNode* root, int& result) {
    if (!root) {
        return;
    }

    result += root->data;
    sumTreeValuesTraverse(root->left, result);
    sumTreeValuesTraverse(root->right, result);
}

int main() {
    // CharNode* root{nullptr};
    // insertNode(root, 'E');
    // insertNode(root, 'C');
    // insertNode(root, 'H');
    // insertNode(root, 'A');
    // insertNode(root, 'D');
    // insertNode(root, 'F');
    // insertNode(root, 'I');
    // insertNode(root, 'B');
    // insertNode(root, 'G');
    // insertNode(root, 'J');
    //
    // deleteFromTree(root, 'H');
    //
    // std::cout << "Inorder Tree:";
    // printTree(root, 1);
    // std::cout << '\n';
    //
    // std::cout << "Preorder Tree:";
    // printTree(root, 2);
    // std::cout << '\n';
    //
    // std::cout << "Postorder Tree:";
    // printTree(root, 3);
    // std::cout << '\n';

    // root
    IntNode* root{new IntNode(8)};

    // left subtree

    root->left = new IntNode(4);

    root->left->right = new IntNode(6);
    root->left->right->left = new IntNode(5);
    root->left->right->right = new IntNode(7);

    root->left->left = new IntNode(2);
    root->left->left->right = new IntNode(3);
    root->left->left->left = new IntNode(1);

    // right subtree

    root->right = new IntNode(12);

    root->right->right = new IntNode(14);
    root->right->right->left = new IntNode(13);
    root->right->right->right = new IntNode(15);

    root->right->left = new IntNode(10);
    root->right->left->left = new IntNode(9);
    root->right->left->right = new IntNode(11);

    std::cout << "Odd Count: " << countOddRecursive(root) << '\n';

    int evenCount{0};
    countEvenTraverse(root, evenCount);
    std::cout << "Even Count: " << evenCount << '\n';

    std::cout << "Tree Height: " << treeHeight(root) << '\n';

    std::cout << "Is Binary Tree: " << isBST(root, -99999, 99999) << '\n';

    std::cout << "Full Binary Tree: " << isFullBinaryTree(root) << '\n';

    std::cout << "# of Double Parent Nodes: " << doubleParentCountRecursive(root) << '\n';

    int dbParentCount{0};
    doubleParentCountTraverse(root, dbParentCount);
    std::cout << "# of Double Parent Nodes (Traverse): " << dbParentCount << '\n';

    std::cout << "Sum of All Node Values: " << sumTreeValuesRecursive(root) << '\n';

    int sumTree{0};
    sumTreeValuesTraverse(root, sumTree);
    std::cout << "Sum of All Node Values (Traverse): " << sumTree << '\n';

    return 0;
}

void insertNode(CharNode*& root, char value) {
    if (!root) {
        CharNode* newPtr{new CharNode(value)};
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

void printTree(CharNode* root, int traversal) {
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

CharNode* searchNode(CharNode* root, char value) {
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

CharNode* getInorderPredecessor(CharNode* root) {
    if (!root) {
        return nullptr;
    }

    if (root->right == nullptr) {
        return root;
    }

    return getInorderPredecessor(root->right);
}

CharNode* getInorderSuccessor(CharNode* root) {
    CharNode* currentPtr{root};

    while (currentPtr != nullptr && currentPtr->left != nullptr) {
        currentPtr = currentPtr->left;
    }

    return currentPtr;
}

void deleteFromTree(CharNode*& root, char value) {
    if (!root) {
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

void deleteNode(CharNode*& root) {
    CharNode* tempPtr{root};

    if (root->left == nullptr) {
        root = root->right;
        delete tempPtr;
    } else if (root->right == nullptr) {
        root = root->left;
        delete tempPtr;
    } else {
        CharNode* targetSuccessor{getInorderSuccessor(root->right)};
        char successorValue{targetSuccessor->data};
        root->data = successorValue;
        deleteFromTree(root->right, successorValue);
    }
}

