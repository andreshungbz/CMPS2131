#include <iostream>
#include "MinHeap.h"

int main() {
    MinHeap heap{};
    int values[] {1, 5, 10, 7, 8, 12, 15};
    for (int i : values) {
        heap.insertNode(i);
    }

    heap.printHeap();
    heap.deleteRootNode();
    heap.deleteRootNode();
    heap.printHeap();

    return 0;
}
