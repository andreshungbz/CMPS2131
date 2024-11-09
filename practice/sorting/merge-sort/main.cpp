#include <iostream>

constexpr int MAX{10};

void merge(int array[], int leftFirstIndex, int leftLastIndex, int rightFirstIndex, int rightLastIndex) {
    int tempArray[MAX]; // temporary array
    int index{leftFirstIndex};
    int saveFirst{leftFirstIndex}; // save for later

    // populate the temporary array in order from the left and right sub-arrays until one of them is empty

    while ((leftFirstIndex <= leftLastIndex) && (rightFirstIndex <= rightLastIndex)) {
        if (array[leftFirstIndex] < array[rightFirstIndex]) {
            tempArray[index] = array[leftFirstIndex];
            ++leftFirstIndex;
        } else {
            tempArray[index] = array[rightFirstIndex];
            ++rightFirstIndex;
        }

        ++index;
    }

    // copy remaining items, only one of these loops will run (the non-empty one)

    while (leftFirstIndex <= leftLastIndex) {
        tempArray[index] = array[leftFirstIndex];
        ++index;
        ++leftFirstIndex;
    }

    while (rightFirstIndex <= rightLastIndex) {
        tempArray[index] = array[rightFirstIndex];
        ++index;
        ++rightFirstIndex;
    }

    // merge from tempArray into array

    for (index = saveFirst; index <= rightLastIndex; ++index) {
        array[index] = tempArray[index];
    }
}

void mergeSort(int array[], int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        int middleIndex{(firstIndex + lastIndex) / 2};
        mergeSort(array, firstIndex, middleIndex);
        mergeSort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, middleIndex + 1, lastIndex);
    }
}

void printArray(const int array[], std::size_t size) {
    std::cout << "Array:";
    for (std::size_t i{0}; i < size; ++i) {
        std::cout << ' ' << array[i];
    }
    std::cout << '\n';
}

int main() {
    int array[MAX] {4, 5, 7, 1, 2, 3, 9, 8, 10, 6};
    printArray(array, MAX);
    mergeSort(array, 0, MAX - 1);
    printArray(array, MAX);

    return 0;
}
