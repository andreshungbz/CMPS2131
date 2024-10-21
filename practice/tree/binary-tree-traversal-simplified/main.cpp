/*Copyright srcmake.com 2018.
// C++ Tree Code
// C++ Preorder, Inorder, and Postorder Traversal
// Official webpage for this tutorial: https://www.srcmake.com/home/trees

/* Compile with:
g++ -std=c++14 main.cpp -o run
./run
*/

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////
/////// NODE ///////
// This struct represents the node in our tree.
struct node
    {
    int value;            // The value 
    struct node* left;    // A pointer to the node for the left child.
    struct node* right;    // A pointer to the node for the right child.
    
    // Constructor
    node(int value)
        {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        }
    };
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////
////// PREORDER TRAVERSAL //////
// Print the nodes, going in preorder traversal.
// The function is passed a pointer of a node in the tree.
void PrintPreorderTraversal(node* node)
    {
    // If the pointer points to null instead of an actual node, stop.
    if(node == NULL)
        { return; }
    
    // Node.
    cout << node->value << " ";
    
    // Left.
    PrintPreorderTraversal(node->left);
    
    // Right.
    PrintPreorderTraversal(node->right);
    }
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////
////// INORDER TRAVERSAL //////
// Print the nodes, going in inorder traversal.
// The function is passed a pointer of a node in the tree.
void PrintInorderTraversal(node* node)
    {
    // If the pointer points to null instead of an actual node, stop.
    if(node == NULL)
        { return; }
    
    // Left.
    PrintInorderTraversal(node->left);
    
    // Node.
    cout << node->value << " ";
    
    // Right.
    PrintInorderTraversal(node->right);
    }
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////
////// POSTORDER TRAVERSAL //////
// Print the nodes, going in postorder traversal.
// The function is passed a pointer of a node in the tree.
void PrintPostorderTraversal(node* node)
    {
    // If the pointer points to null instead of an actual node, stop.
    if(node == NULL)
        { return; }
    
    // Left.
    PrintPostorderTraversal(node->left);
    
    // Right.
    PrintPostorderTraversal(node->right);
    
    // Node.
    cout << node->value << " ";
    }
/////////////////////////////////////////////////////


//////////////////////////////////////////////////////
////// MAIN //////
int main() 
    {
    cout << "Program started.\n";
    
    // Create a new node and have a pointer to it, which we'll call root.
    node* root = new node(4);
    
    // Add the rest of the nodes of the tree.
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    
    // Pass the root node to the traversal functions.
    cout << "Preorder Traversal: ";
    PrintPreorderTraversal(root);
    cout << endl;
    
    cout << "Inorder Traversal: ";
    PrintInorderTraversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    PrintPostorderTraversal(root);
    cout << endl;
    
    cout << "Program ended.\n";
    return 0;
    }
//////////////////////////////////////////////////////