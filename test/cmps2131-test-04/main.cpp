#include <iostream>
#include <vector>
#include <string>

#include <algorithm> // for std::swap

//This class has two data members to maintain the priority and description. Also has one constructor to initialize the two //data members.
class Task {
public:
    int priority{};
    std::string description{};
    Task(int prio, const std::string& desc) : priority(prio), description(desc) {}
};

//This class has one data member, already added.
//Also needs functions to insert task and to return the highest priority task
class PriorityQueue {
public:
    // public functions
    void insertTask(int prio, const std::string& desc);
    // the testing code suggests returning just the description of the highest priority task
    std::string getHighestPriorityTask();
private:
    // A vector to store tasks as a max-heap
    std::vector<Task> heap;

    // private internal functions that manage heap
    int getLeftChild(int index);
    int getRightChild(int index);
    int getParent(int index);
    void reHeapUp(int bottomIndex);
    void reHeapDown(int rootIndex, int bottomIndex);
};


int main() {
    PriorityQueue pq;
    pq.insertTask(5, "Complete project report");
    pq.insertTask(2, "Check emails");
    pq.insertTask(10, "Prepare presentation");

    std::cout << "Highest priority task: " << pq.getHighestPriorityTask() << std::endl;
    std::cout << "Highest priority task: " << pq.getHighestPriorityTask() << std::endl;
    std::cout << "Highest priority task: " << pq.getHighestPriorityTask() << std::endl;

    return 0;
}

//Hints

//parentindex = (index-1)/2

//to push something on a vector push_back(object of class Task)

// PriorityQueue Member Function Implementations

int PriorityQueue::getLeftChild(int index) {
    return index * 2 + 1;
}

int PriorityQueue::getRightChild(int index) {
    return index * 2 + 2;
}

int PriorityQueue::getParent(int index) {
    return (index - 1) / 2;
}

void PriorityQueue::insertTask(int prio, const std::string &desc) {
    Task newTask{prio, desc};
    heap.push_back(newTask);
    reHeapUp(heap.size() - 1);
}

void PriorityQueue::reHeapUp(int bottomIndex) {
    if (bottomIndex > 0) {
        int parentIndex{getParent(bottomIndex)};

        if (heap[parentIndex].priority < heap[bottomIndex].priority) {
            std::swap(heap[parentIndex], heap[bottomIndex]);
            reHeapUp(parentIndex);
        }
    }
}

std::string PriorityQueue::getHighestPriorityTask() {
    if (heap.empty()) {
        return "\0";
    }

    std::string highestPrioDesc{heap[0].description};
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    reHeapDown(0, heap.size() - 1);

    return highestPrioDesc;
}

void PriorityQueue::reHeapDown(int rootIndex, int bottomIndex) {
    int maxIndex;
    int leftIndex{getLeftChild(rootIndex)};
    int rightIndex{getRightChild(rootIndex)};

    if (leftIndex <= bottomIndex) {
        if (leftIndex == bottomIndex) {
            maxIndex = leftIndex;
        } else {
            maxIndex = heap[rightIndex].priority > heap[leftIndex].priority ? rightIndex : leftIndex;
        }

        if (heap[rootIndex].priority < heap[maxIndex].priority) {
            std::swap(heap[rootIndex], heap[maxIndex]);
            reHeapDown(maxIndex, bottomIndex);
        }
    }
}
