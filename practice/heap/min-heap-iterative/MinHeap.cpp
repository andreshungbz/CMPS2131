#include <iostream>
#include <algorithm>
#include "MinHeap.h"

int MinHeap::getLeftChild(int index) {
    return index * 2 + 1;
}

int MinHeap::getRightChild(int index) {
    return index * 2 + 2;
}

int MinHeap::getParent(int index) {
    return (index - 1) / 2;
}

void MinHeap::printHeap() const {
    std::cout << "Heap:";
    for (int i{0}; i < heap.size(); ++i) {
        std::cout << " [" << i << ']' << heap[i];
    }
    std::cout << '\n';
}

void MinHeap::insertNode(int value) {
    heap.push_back(value);
    reHeapUp(heap.size() - 1);
}

void MinHeap::reHeapUp(int bottomIndex) {
    while (bottomIndex > 0) {
        int parentIndex{getParent(bottomIndex)};
        if (heap[parentIndex] > heap[bottomIndex]) {
            std::swap(heap[parentIndex], heap[bottomIndex]);
        }
        bottomIndex = parentIndex;
    }
}

void MinHeap::deleteRootNode() {
    std::cout << "Deleted: " << heap.front() << '\n';
    heap[0] = heap.back();
    heap.erase(heap.end());
    reHeapDown(0, heap.size() - 1);
}

void MinHeap::reHeapDown(int rootIndex, int bottomIndex) {
    while (getLeftChild(rootIndex) <= bottomIndex) {
        int leftIndex{getLeftChild(rootIndex)};
        int rightIndex{getRightChild(rootIndex)};
        int minChildIndex;

        if (leftIndex == bottomIndex) {
            minChildIndex = leftIndex;
        } else {
            minChildIndex = heap[rightIndex] < heap[leftIndex] ? rightIndex : leftIndex;
        }

        if (heap[rootIndex] > heap[minChildIndex]) {
            std::swap(heap[rootIndex], heap[minChildIndex]);
        }

        rootIndex = minChildIndex;
    }
}
