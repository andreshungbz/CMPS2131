// Node class-template definition for singly-linked lists

#ifndef LISTNODE_H
#define LISTNODE_H

template<typename NODETYPE>
class List; // forward declaration for declaring as a friend class to ListNode

template<typename NODETYPE>
class ListNode {
    friend class List<NODETYPE>; // this enables List class to access private/protected members of this class

    // friend declaration for exercise 19-06 to access private/protected members
    template<typename T>
    friend void concatenate(List<T>& a, const List<T>& b);

    // friend declaration for exercise 19-07
    template<typename T>
    friend void merge(List<T>& a, const List<T>& b, const List<T>& c);

    // friend declaration for exercise 19-09
    template<typename T>
    friend List<T> createReverseList(const List<T>& list);

public:
    explicit ListNode(const NODETYPE& info) : data{info}, nextPtr{nullptr} {} // constructor
    NODETYPE getData() const { return data; }
private:
    NODETYPE data;
    ListNode<NODETYPE>* nextPtr;
};

#endif // LISTNODE_H
