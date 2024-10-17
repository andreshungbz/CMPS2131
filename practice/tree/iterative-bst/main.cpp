#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

void findNode(Node* root, int value, Node*& nodePtr, Node*& parentPtr) {
    parentPtr = nullptr;
    nodePtr = root;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
