#include <iostream>

constexpr int MAX{5};
int queue[MAX];
int front{-1};
int back{-1};
int length{0};

void increment(int& number) {
    if (number + 1 == MAX) {
        number = 0;
    } else {
        ++number;
    }
}

int size() {
    return length;
}

void printQueue() {
    std::cout << "Queue:";
    int frontCopy{front};
    for (int i{0}; i < size(); ++i) {
        std::cout << ' ' << queue[frontCopy];
        increment(frontCopy);
    }
    std::cout << '\n';
}

void enqueue(int value) {
    if (size() == MAX) {
        std::cout << "Queue is full.\n";
        return;
    }

    if (front == -1 || back == -1) {
        queue[0] = value;
        ++front;
        ++back;
        ++length;
        return;
    }

    increment(back);
    queue[back] = value;
    ++length;
}

void dequeue() {
    if (front == -1 || back == -1) {
        std::cout << "Queue is empty.\n";
        return;
    }

    if (front == back) {
        front = -1;
        back = -1;
        length = 0;
        return;
    }

    increment(front);
    --length;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printQueue();
    std::cout << "Size: " << size() << '\n';

    enqueue(6);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printQueue();
    std::cout << "Size: " << size() << '\n';

    return 0;
}
