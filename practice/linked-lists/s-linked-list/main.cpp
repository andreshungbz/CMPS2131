#include <iostream>
#include "List.h"

int main() {
    // create empty list
    List list{};

    // populate list with nodes
    for (int i{1}; i <= 10; ++i) {
        list.createNode(i);
    }

    // display list
    list.display();

    return 0;
}
