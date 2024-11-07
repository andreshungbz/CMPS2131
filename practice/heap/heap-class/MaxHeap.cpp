#include <iostream>
#include "MaxHeap.h"

int MaxHeap::leftChild(int i) {
    return 2 * i + 1;
}

int MaxHeap::rightChild(int i) {
    return 2 * i + 2;
}

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

void MaxHeap::print() const {
    std::cout << "Heap:";
    for (int i{0}; i < heap.size(); ++i) {
        std::cout << " [" << i << ']' << heap[i];
    }
    std::cout << '\n';
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    reHeapUp(heap.size() - 1);
}

void MaxHeap::reHeapUp(int bottomIndex) {
    if (bottomIndex > 0) { // stop at root
        int parentIndex{parent(bottomIndex)};

        if (heap[parentIndex] < heap[bottomIndex]) {
            // swap
            int temp{heap[parentIndex]};
            heap[parentIndex] = heap[bottomIndex];
            heap[bottomIndex] = temp;

            reHeapUp(parentIndex);
        }
    }
}

void MaxHeap::deleteRoot() {
    std::cout << "Deleted: " << heap.front() << '\n';
    heap.erase(heap.begin());
    reHeapDown(heap.size() - 1);
}
