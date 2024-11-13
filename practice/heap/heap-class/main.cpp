#include <iostream>
#include "MaxHeap.h"

int main() {
    int values[] {45, 40, 35, 20, 15, 30, 25, 10, 5};
    MaxHeap maxHeap{};

    for (int i : values) {
        maxHeap.insert(i);
    }

    // initial
    maxHeap.print();

    // delete root
    maxHeap.deleteNode(0);
    maxHeap.deleteNode(0);
    maxHeap.print();

    // search and delete specific node
    int nodeIndex(maxHeap.searchNode(20));
    maxHeap.deleteNode(nodeIndex);
    maxHeap.print();

    return 0;
}
