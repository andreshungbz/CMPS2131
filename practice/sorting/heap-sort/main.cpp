#include <iostream>
#include <algorithm>

constexpr int MAX{10};

void printArray(const int array[], std::size_t size) {
    std::cout << "Array:";
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << ' ' << array[i];
    }
    std::cout << '\n';
}

void reHeapDown(int array[], int startIndex, int endIndex) {
    int maxChildIndex;
    int leftChildIndex{startIndex * 2 + 1};
    int rightChildIndex{startIndex * 2 + 2};

    if (leftChildIndex <= endIndex) {
        if (leftChildIndex == endIndex) {
            maxChildIndex = leftChildIndex;
        } else {
            maxChildIndex = array[rightChildIndex] > array[leftChildIndex] ? rightChildIndex : leftChildIndex;
        }

        if (array[startIndex] < array[maxChildIndex]) {
            std::swap(array[startIndex], array[maxChildIndex]);
            reHeapDown(array, maxChildIndex, endIndex);
        }
    }
}

void heapSort(int array[], int size) {
    // convert array into a max heap
    // size / 2 - 1 gives the last non-leaf node
    for (int i{size / 2 - 1}; i >= 0; --i) {
        reHeapDown(array, i, size - 1);
    }

    // sort the array, starting backwards and putting the largest element
    for (int i{size - 1}; i >= 1; --i) {
        std::swap(array[0], array[i]);
        reHeapDown(array, 0, i - 1); // i - 1 to not count the sorted element
    }
}

int main() {
    int array[MAX] {4, 5, 7, 1, 2, 3, 9, 8, 10, 6};
    printArray(array, MAX);
    heapSort(array, MAX);
    printArray(array, MAX);

    return 0;
}
