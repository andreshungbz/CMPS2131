// 19.8 Summing and Averaging Elements in a List

#include <iostream>
#include <random>
#include "List.h"

int roll100() {
    static std::random_device rd{};
    static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 mt{ss};
    static std::uniform_int_distribution<> dice{0, 100};

    return dice(mt);
}

// works best starting with an empty list
template<typename T>
void insertOrdered(List<T>& list, const T& value) {

}

int main() {
    List<int> list{};

    for (int i{0}; i < 25; ++i) {

    }

    list.print();
}