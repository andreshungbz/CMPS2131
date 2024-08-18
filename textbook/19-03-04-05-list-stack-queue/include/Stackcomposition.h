// Stack class template with a composed List object

#ifndef STACKCOMPOSITION_H
#define STACKCOMPOSITION_H



#include "List.h" // List class definition

template<typename STACKTYPE>
class Stack {
public:
    // no constructor; List constructor does initialization

    // push calls stackList object's insertAtFront member function
    void push(const STACKTYPE& data) {
        stackList.insertAtFront(data);
    }

    // pop calls stackList object's removeFromFront member function
    bool pop(STACKTYPE& data) {
        return stackList.removeFromFront(data);
    }

    // isStackEmpty calls stackList object's isEmpty member function
    bool isStackEmpty() const {
        return stackList.isEmpty();
    }

    // printStack calls stackList object's print member function
    void printStack() const {
        stackList.print();
    }
private:
    List<STACKTYPE> stackList; // composed List object
};



#endif //STACKCOMPOSITION_H
