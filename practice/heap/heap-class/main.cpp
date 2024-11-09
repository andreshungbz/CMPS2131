#include <iostream>
#include "MaxHeap.h"

int main() {
    int values[] {45, 40, 35, 20, 15, 30, 25, 10, 5};
    MaxHeap maxHeap{};

    for (int i : values) {
        maxHeap.insert(i);
    }

    maxHeap.print();
    maxHeap.deleteRoot();
    maxHeap.deleteRoot();
    maxHeap.print();

    return 0;
}
