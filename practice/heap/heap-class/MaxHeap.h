#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

class MaxHeap {
public:
    MaxHeap() {}
    int leftChild(int);
    int rightChild(int);
    int parent(int);
    void print() const;
    void insert(int);
    void reHeapUp(int);
    void deleteRoot();
    void reHeapDown(int);
private:
    std::vector<int> heap{};
};



#endif // MAXHEAP_H
