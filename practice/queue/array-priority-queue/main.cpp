#include <iostream>

// Assumptions and Specifications

// The highest priority item exists in the first array position.
// 0 is the default lowest priority.
// Positive value for priority indicate higher importance and are dequeued first.
// Higher "tiers" of priority exist, corresponding with larger positive value.
//      e.g. 2 has a higher priority than 1.
// Same higher priorities are added at the end of that priority "tier".
//      e.g. adding node with priority 1 [n1] in queue [HEAD] [p2] [p1] [p1] [p0] [p0] [TAIL]
//           results in [HEAD] [p2] [p1] [p1] [n1] [p0] [p0] [TAIL]
// Negative value for priority are invalid.

class Node {
public:
    int data{};
    int priority{0};

    // for array implementation, link is not needed
    // Node* next{nullptr};
};

class ArrayPriorityQueue {
public:
    void Enqueue(int value, int priority = 0) {
        // short-circuit if array is full
        if (indexToLast >= MAX_SIZE) {
            std::cout << "Queue is full.\n";
            return;
        }

        // short-circuit if priority parameter is invalid
        if (priority < 0) {
            std::cout << "Invalid priority.\n";
            return;
        }

        // create new node
        Node* newPtr{new Node()};
        newPtr->data = value;
        newPtr->priority = priority;

        // insert like a regular queue
        // condition 1: empty queue base case
        // condition 2: regular priority
        if (indexToLast == -1 || priority == 0) {
            priorityQueue[indexToLast + 1] = newPtr;
            ++indexToLast;
            return;
        }

        // there should be at least one node in the queue past this point

        // find the proper index for the node to insert based on its priority
        int indexToInsert{0};
        while (priority <= priorityQueue[indexToInsert]->priority) {
            ++indexToInsert;
        }

        // traversing backwards, shift every node up to create the space for the node to insert
        // length is represented by indexToLast + 1; needed to properly loop
        for (int i{indexToLast + 1}; i > indexToInsert; --i) {
            // index i is the new upper index
            priorityQueue[i] = priorityQueue[i - 1];
        }

        // insert node and increment length
        priorityQueue[indexToInsert] = newPtr;
        ++indexToLast;
    }

    // because Enqueue was implemented to insert nodes in proper order,
    // Dequeue just needs to remove the first index
    void Dequeue() {
        // short-circuit if queue is empty
        if (indexToLast == -1) {
            std::cout << "Queue is empty.\n";
            return;
        }

        // delete first node with has the highest priority
        delete priorityQueue[0];
        --indexToLast;

        // if queue is now empty, reset first node and return
        if (indexToLast == -1) {
            priorityQueue[0] = nullptr;
            return;
        }

        // there should at least one node to shift past this point

        // shift every element down
        for (int i{0}; i < indexToLast + 1; ++i) {
            priorityQueue[i] = priorityQueue[i + 1];
        }
        // make sure that last node shifted is removed
        priorityQueue[indexToLast + 1] = nullptr;
    }

    // simple print function
    void print() {
        std::cout << "Array Priority Queue:";
        for (int i{0}; i < indexToLast + 1; ++i) {
            std::cout << ' ' << priorityQueue[i]->data;
        }
        std::cout << '\n';
    }
private:
    static constexpr int MAX_SIZE{100};
    Node* priorityQueue[MAX_SIZE] {nullptr};
    int indexToLast{-1}; // keep track of the queue length
};

int main() {
    ArrayPriorityQueue test{};

    test.Enqueue(5, 0);
    test.Enqueue(6, 0);
    test.Enqueue(7, 1);
    test.Enqueue(8, 1);
    test.Enqueue(9, 2);
    test.Enqueue(10, 1);

    test.print();

    test.Dequeue();
    test.Dequeue();
    test.Dequeue();
    test.Dequeue();

    test.print();

    // In the worst case, array implementation Enqueue is O(n).
    // Inserting at the beginning and shifting every other node up.
    // My implementation does have one case of O(1) which is enqueuing at the end of priority 0.

    // In the worst case, array implementation Dequeue is O(n) as well.
    // Deletion is done at the beginning, which means shifting every other node down

    // Heap implementation has O(log n) for both Enqueue and Dequeue.

    // Array implementation might work better with not many nodes, infrequent insertions and deletions
    // and simpler to implement. Heap implementation works better with larger number of nodes
    // and frequent insertions and deletions.

    return 0;
}
