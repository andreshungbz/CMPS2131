//
// Created by andreshung on 11/20/24.
//

#ifndef MINHEAPPQ_H
#define MINHEAPPQ_H

#include <vector>

class MinHeapPQ {
public:
    int getLeftChild(int index);
    int getRightChild(int index);
    int getParent(int index);
    void printArray();
    void enqueue(int value);
    void reHeapUp(int rootIndex, int bottomIndex);
    int dequeue(int index);
    void reHeapDown(int rootIndex, int bottomIndex);
    int searchNode(int value);
private:
    std::vector<int> heap{};
};



#endif //MINHEAPPQ_H
