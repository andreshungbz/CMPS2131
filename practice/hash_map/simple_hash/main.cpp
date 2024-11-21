#include <iostream>
#include <string>

class Node {
public:
    std::string key{};
    int age{};
    Node* next{nullptr};
    explicit Node(std::string name, int value) : key(name), age(value) {}
};

int hashFunction(const std::string& name, int size) {
    int charSum{};
    for (char c : name) {
        int charValue{c};
        charSum += charValue;
    }

    return charSum % size;
}

void insertAge(Node*& root, std::string name, int value) {
    if (root == nullptr) {
        root = new Node(name, value);
        return;
    }

    if (root->next == nullptr) {
        root->next = new Node(name, value);
        return;
    }

    insertAge(root->next, name, value);
}

int main() {
    constexpr int MAX{7};
    Node* hashTable[MAX] {};

    std::string name{"john"};
    int hash{hashFunction(name, MAX)};
    insertAge(hashTable[hash], name, 22);

    std::string name2{"joim"};
    int hash2{hashFunction(name2, MAX)};
    insertAge(hashTable[hash], name2, 25);

    return 0;
}