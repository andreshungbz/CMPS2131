#include <iostream>

#include "MinHeapPQ.h"

int main() {
    MinHeapPQ queue{};
    int values[] = {5, 15, 10, 25, 30, 40, 35, 50, 60};

    for (int v : values) {
        queue.enqueue(v);
    }

    queue.printArray();
    queue.dequeue(queue.searchNode(15));
    queue.printArray();

    return 0;
}
