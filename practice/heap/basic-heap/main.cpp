#include <iostream>

constexpr int MAX{10};
int length{0};
int heap[MAX];

bool isHeapEmpty() {
    return length == 0;
}

bool isHeapFull() {
    return length == MAX;
}

void printHeapArray() {
    std::cout << "Heap:";
    for (int i{0}; i < length; ++i) {
        std::cout << " [" << i << ']' << heap[i];
    }
    std::cout << '\n';
}

void reHeapUp(int rootIndex, int bottomIndex) {
    // the base case is if we are within bounds, stop at root
    if (bottomIndex > rootIndex) {
        int parentIndex{(bottomIndex - 1) / 2}; // determine element's parent

        // swap and continue re-heap up if element value is greater than parent's value
        if (heap[parentIndex] < heap[bottomIndex]) {
            int temp{heap[parentIndex]};
            heap[parentIndex] = heap[bottomIndex];
            heap[bottomIndex] = temp;

            reHeapUp(rootIndex, parentIndex);
        }
    }
}

void enqueue(int value) {
    // stop if heap is full
    if (isHeapFull()) {
        std::cout << "Heap is full.\n";
        return;
    }

    ++length; // increment length
    heap[length - 1] = value; // add new element
    reHeapUp(0, length - 1); // move new element up as necessary
}

void reHeapDown(int rootIndex, int bottomIndex) {
    int leftChildIndex{(rootIndex * 2) + 1}; // get left child
    int rightChildIndex{(rootIndex * 2) + 2}; // get right child
    int maxChildIndex;

    // the base case is if we are within bounds, leaf nodes will be out of bounds
    if (leftChildIndex <= bottomIndex) {
        // check if current root node has only a single child, which can only happen at the last node
        // because heap is a complete tree
        if (leftChildIndex == bottomIndex) {
            // because heap is complete tree, a single child node's child has to be on the left
            maxChildIndex = leftChildIndex;
        } else { // in case of a node with two children, set max child to the index of the larger child
            if (heap[leftChildIndex] <= heap[rightChildIndex]) {
                maxChildIndex = rightChildIndex;
            } else {
                maxChildIndex = leftChildIndex;
            }
        }

        // if root value is less than the max child, swap and re-heap down further
        if (heap[rootIndex] < heap[maxChildIndex]) {
            int temp{heap[rootIndex]};
            heap[rootIndex] = heap[maxChildIndex];
            heap[maxChildIndex] = temp;

            reHeapDown(maxChildIndex, bottomIndex);
        }
    }
}

void dequeue(int& result) {
    // stop if heap is empty
    if (isHeapEmpty()) {
        std::cout << "Heap is empty.\n";
        return;
    }

    result = heap[0]; // pass the value of the dequeued element back to caller
    heap[0] = heap[length - 1]; // take the last element and assign its value to root (shape property)
    --length; // decrement length
    reHeapDown(0, length - 1); // move root element down as necessary
}

int main() {
    int values[] {27, 35, 23, 22, 4, 45, 21, 5, 42, 19};
    for (int value : values) {
        enqueue(value);
    }

    printHeapArray();

    int dequeuedValue;
    dequeue(dequeuedValue);
    std::cout << "Value " << dequeuedValue << " was dequeued.\n";
    printHeapArray();

    return 0;
}
