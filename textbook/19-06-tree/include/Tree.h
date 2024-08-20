// Tree class-template definition

#ifndef TREE_H
#define TREE_H



#include <iostream>
#include "TreeNode.h"

// Tree class-template definition
template<typename NODETYPE>
class Tree {
public:
    // insert node in Tree
    void insertNode(const NODETYPE& value) {
        insertNodeHelper(&rootPtr, value);
    }

    // begin preorder traversal of Tree
    void preOrderTraversal() const {
        preOrderHelper(rootPtr);
    }

    // begin inorder traversal of Tree
    void inOrderTraversal() const {
        inOrderHelper(rootPtr);
    }

    // begin postorder traversal of Tree
    void postOrderTraversal() const {
        postOrderHelper(rootPtr);
    }

private:
    TreeNode<NODETYPE>* rootPtr{nullptr};

    // utility function called by insertNode; receives a pointer
    // to a pointer so that the function can modify pointer's value
    void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value);

    // utility function to perform preorder traversal of Tree
    void preOrderHelper(TreeNode<NODETYPE>* ptr) const;

    // utility function to perform inorder traversal of Tree
    void inOrderHelper(TreeNode<NODETYPE>* ptr) const;

    // utility function to perform postorder traversal of Tree
    void postOrderHelper(TreeNode<NODETYPE>* ptr) const;
};

template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
    // subtree is empty; create new TreeNode containing value
    if (*ptr == nullptr) {
        *ptr = new TreeNode<NODETYPE>{value};
    } else { // subtree is not empty
        if (value < (*ptr)->data) { // data to insert is less than data in current node
            insertNodeHelper(&((*ptr)->leftPtr), value);
        } else if (value > (*ptr)->data) { // data to insert is greater than data in current node
            insertNodeHelper(&((*ptr)->rightPtr), value);
        } else { // duplicate data value ignored
            std::cout << value << " dup" << std::endl;
        }
    }
}

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE>* ptr) const {
    if (ptr != nullptr) {
        // prints roots first then leaves
        std::cout << ptr->data << ' '; // process node
        preOrderHelper(ptr->leftPtr); // traverse left subtree
        preOrderHelper(ptr->rightPtr); // traverse right subtree
    }
}

template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE>* ptr) const {
    if (ptr != nullptr) {
        // prints lowest to highest
        inOrderHelper(ptr->leftPtr); // traverse left subtree
        std::cout << ptr->data << ' '; // process node
        inOrderHelper(ptr->rightPtr); // traverse right subtree

        // prints highest to lowest
        // inOrderHelper(ptr->rightPtr); // traverse right subtree
        // std::cout << ptr->data << ' '; // process node
        // inOrderHelper(ptr->leftPtr); // traverse left subtree
    }
}

template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE>* ptr) const {
    if (ptr != nullptr) {
        // prints leaves first then roots
        postOrderHelper(ptr->leftPtr); // traverse left subtree
        postOrderHelper(ptr->rightPtr); // traverse right subtree
        std::cout << ptr->data << ' '; // process node
    }
}



#endif // TREE_H
