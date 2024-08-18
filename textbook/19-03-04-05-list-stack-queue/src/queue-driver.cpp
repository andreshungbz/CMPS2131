// Queue-processing program

#include <iostream>
#include "Queue.h" // Queue class definition

int main() {
    Queue<int> intQueue; // create Queue of integers

    std::cout << "processing an integer Queue\n";

    // enqueue integers onto intQueue
    for (int i{0}; i < 3; ++i) {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    int dequeueInteger; // store dequeued integer

    // dequeue integers from intQueue
    while (!intQueue.isQueueEmpty()) {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeued\n";
        intQueue.printQueue();
    }

    Queue<double> doubleQueue; // create Queue of doubles
    double value {1.1};

    std::cout << "processing a double Queue\n";

    // enqueue floating-point values onto doubleQueue
    for (int j{0}; j < 3; ++j) {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1;
    }

    double dequeueDouble; // store dequeued double

    // dequeue floating-point values from doubleQueue
    while (!doubleQueue.isQueueEmpty()) {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeued\n";
        doubleQueue.printQueue();
    }
}