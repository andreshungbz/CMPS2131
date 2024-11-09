#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

class MinHeap {
public:
    static int getLeftChild(int index);
    static int getRightChild(int index);
    static int getParent(int index);
    void printHeap() const;
    void insertNode(int value);
    void reHeapUp(int bottomIndex);
    void deleteRootNode();
    void reHeapDown(int rootIndex, int bottomIndex);
private:
    std::vector<int> heap{};
};



#endif // MINHEAP_H
