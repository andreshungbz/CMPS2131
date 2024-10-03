#include <iostream>
#include <queue>

void printQueue(std::queue<int> queueCopy) {
    std::cout << "Queue:";
    while (!queueCopy.empty()) {
        std::cout << ' ' << queueCopy.front();
        queueCopy.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::queue<int> queue{};

    queue.push(1);
    queue.push(2);
    queue.push(3);

    printQueue(queue);
    std::cout << "Size: " << queue.size() << '\n';

    queue.pop();
    queue.pop();

    printQueue(queue);
    std::cout << "Size: " << queue.size() << '\n';

    return 0;
}
