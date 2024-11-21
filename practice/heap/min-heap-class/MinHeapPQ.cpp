//
// Created by andreshung on 11/20/24.
//

#include <algorithm>
#include <iostream>

#include "MinHeapPQ.h"

int MinHeapPQ::getLeftChild(int index) {
    return index * 2 + 1;
}

int MinHeapPQ::getRightChild(int index) {
    return index * 2 + 2;
}

int MinHeapPQ::getParent(int index) {
    return (index - 1) / 2;
}

void MinHeapPQ::printArray() {
    std::cout << "Heap:";
    for (std::size_t i{0}; i < heap.size(); ++i) {
        std::cout << " [" << i << ']' << heap[i];
    }
    std::cout << '\n';
}

void MinHeapPQ::enqueue(int value) {
    heap.push_back(value);
    reHeapUp(0, heap.size() - 1);
}

void MinHeapPQ::reHeapUp(int rootIndex, int bottomIndex) {
    if (bottomIndex > rootIndex) {
        int parentIndex{getParent(bottomIndex)};

        if (heap[parentIndex] > heap[bottomIndex]) {
            std::swap(heap[parentIndex], heap[bottomIndex]);
            reHeapUp(rootIndex, parentIndex);
        }
    }
}

int MinHeapPQ::dequeue(int index) {
    if (heap.empty() || (index > (heap.size() - 1) && index < 0)) {
        return -1;
    }

    int item{heap[index]};
    heap[index] = heap[heap.size() - 1];
    heap.pop_back();
    reHeapDown(index, heap.size() - 1);

    return item;
}

void MinHeapPQ::reHeapDown(int rootIndex, int bottomIndex) {
    int minIndex;
    int leftIndex{getLeftChild(rootIndex)};
    int rightIndex{getRightChild(rootIndex)};

    if (leftIndex <= bottomIndex) {
        if (leftIndex == bottomIndex) {
            minIndex = leftIndex;
        } else {
            minIndex = heap[rightIndex] < heap[leftIndex] ? rightIndex : leftIndex;
        }

        if (heap[rootIndex] > heap[minIndex]) {
            std::swap(heap[rootIndex], heap[minIndex]);
            reHeapDown(minIndex, bottomIndex);
        }
    }
}

int MinHeapPQ::searchNode(int value) {
    for (int i{0}; i < heap.size(); ++i) {
        if (heap[i] == value) {
            return i;
        }
    }

    return -1;
}
