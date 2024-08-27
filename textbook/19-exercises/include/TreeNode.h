// TreeNode class-template definition

#ifndef TREENODE_H
#define TREENODE_H



// forward declaration of class Tree
template<typename NODETYPE> class Tree;

// TreeNode class-template definition
template<typename NODETYPE>
class TreeNode {
    friend class Tree<NODETYPE>;
public:
    // constructor
    TreeNode(const NODETYPE& d) : data{d} {}

    // return copy of node's data
    NODETYPE getData() const {return data;}
private:
    TreeNode<NODETYPE>* leftPtr{nullptr}; // pointer to left subtree
    NODETYPE data;
    TreeNode<NODETYPE>* rightPtr{nullptr}; // pointer to right subtree
};



#endif // TREENODE_H