// Creating and traversing a binary tree

#include <iostream>
#include <iomanip>
#include "Tree.h" // Tree class definition

int main() {
    Tree<int> intTree; // create Tree of int values

    std::cout << "Enter 10 integer values:\n";

    // insert 10 integers to intTree
    for (int i{0}; i < 10; ++i) {
        int intValue{0};
        std::cin >> intValue;
        intTree.insertNode(intValue);
    }

    std::cout << "\nPreorder traversal\n";;
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";;
    intTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    Tree<double> doubleTree; // create Tree of double values

    std::cout << std::fixed << std::setprecision(1)
                << "\n\nEnter 10 double values:\n";

    // insert 10 double values to doubleTree
    for (int j{0}; j < 10; ++j) {
        double doubleValue{0.0};
        std::cin >> doubleValue;
        doubleTree.insertNode(doubleValue);
    }

    std::cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();

    std::cout << std::endl;
}