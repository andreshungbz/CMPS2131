#include <iostream>
#include <cmath>
#include <cctype>

class Node {
public:
    int data;
    Node* next;
};

Node* stackHead{nullptr};

bool isEmpty();
void push(int value);
int pop();
int returnDigit(const char c);

int evaluateExpression(const char* postfix, int size);

int main()
{
    // char postfix[100] = {'8', '2', '3', '^', '/', '2', '3', '*', '+', '5', '1', '*', '-'};
    // int size = sizeof(postfix)/sizeof(postfix[0]);

    // I am using my own initializing of the postfix and size

    const char* postfix = "823^/23*+51*-";

    int size{0};
    const char* counter{postfix};
    while (*counter != '\0') {
        ++size;
        counter++;
    };

    int result = evaluateExpression(postfix, size);

    std::cout << "result: " << result << '\n';

    return 0;
}

bool isEmpty() {
    return stackHead == nullptr;
}

void push(int value) {
    Node* newPtr{new Node()};
    newPtr->data = value;
    newPtr->next = nullptr;

    if (isEmpty()) {
        stackHead = newPtr;
        return;
    }

    newPtr->next = stackHead;
    stackHead = newPtr;
}

int pop() {
    // assumption: -999999 indicates invalid number
    if (isEmpty()) {
        return -999999;
    }

    Node* tempPtr{stackHead};
    int popped{tempPtr->data};
    stackHead = stackHead->next;
    delete tempPtr;

    return popped;
}

int returnDigit(const char c) {
    switch (c) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -999999;
    }
}

int evaluateExpression(const char* postfix, int size) {
    for (int i{0}; i < size; ++i) {
        char character{postfix[i]};

        if (std::isdigit(character)) {
            push(returnDigit(character));
        } else {
            int x{pop()};
            int y{pop()};

            switch (character) {
            case '^':
                push(std::pow(y, x));
                break;
            case '/':
                push(y/x);
                break;
            case '*':
                push(y*x);
                break;
            case '+':
                push(y+x);
                break;
            case '-':
                push(y-x);
                break;
            default:
                break;
            }
        }
    }

    return pop();
}
