// Stack class-template definition

#ifndef STACK_H
#define STACK_H



#include "List.h" // List class definition

template<typename STACKTYPE>
class Stack : private List<STACKTYPE> {
public:
    // disambiguate insertAtFront and removeFromFront
    // alternatively use this-> to specify the List function
    using List<STACKTYPE>::insertAtFront;
    using List<STACKTYPE>::removeFromFront;

    // push calls the List function insertAtFront
    void push(const STACKTYPE& data) {
        insertAtFront(data);
    }

    // pop calls the List function removeFromFront
    bool pop(STACKTYPE& data) {
        return removeFromFront(data);
    }

    // isStackEmpty calls the List function isEmpty
    bool isStackEmpty() const {
        return this->isEmpty();
    }

    // printStack calls the List function print
    void printStack() const {
        this->print();
    }
};



#endif // STACK_H
