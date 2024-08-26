// Stack class template implenetation

#ifndef STACK_H
#define STACK_H

#include "List.h"

template<typename STACKTYPE>
class Stack : private List<STACKTYPE> {
public:
    void push(const STACKTYPE& data);
    bool pop(STACKTYPE& data);
    bool isStackEmpty() const;
    void printStack() const;
};

template<typename STACKTYPE>
void Stack<STACKTYPE>::push(const STACKTYPE& data) {
    this->insertAtFront(data);
}

template<typename STACKTYPE>
bool Stack<STACKTYPE>::pop(STACKTYPE& data) {
    return this->removeFromFront(data);
}

template<typename STACKTYPE>
bool Stack<STACKTYPE>::isStackEmpty() const {
    return this->isEmpty();
}

template<typename STACKTYPE>
void Stack<STACKTYPE>::printStack() const {
    this->print();
}

#endif // STACK_H
