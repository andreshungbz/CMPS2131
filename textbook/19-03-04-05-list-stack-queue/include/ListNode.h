// ListNode class-template definition

#ifndef LISTNODE_H
#define LISTNODE_H



// forward declaration of class List required to announce that class
// List exists so it can be used in the friend declaration at line 14
template <typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode {
friend class List<NODETYPE>; // make List a friend

public:
    explicit ListNode(const NODETYPE& info); // constructor

    NODETYPE getData() const; // return data in node
private:
    NODETYPE data; // data
    ListNode<NODETYPE>* nextPtr; // next node in list
};

// In C++, template classes and functions must be fully defined in the header file
// because the compiler needs to see the complete definition of the template when it
// instantiates it with specific types.

template<typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& info)
    : data{info}, nextPtr{nullptr} {}

template<typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const {
    return data;
}



#endif // LISTNODE_H
