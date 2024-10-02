#include <iostream>

void replacer(char* input) {
    int length{0};
    char* start{input};

    while (*start != '\0') {
        ++length;
        ++start;
    }

    if (length < 4) {
        while (*input != '\0') {
            *input++ = '$';
        }
    } else {
        while (*input != '\0') {
            *input++ = '#';
        }
    }
}

int main() {
    char input1[] = "hello";
    char input2[] = "fun";

    std::cout << "input1: " << input1 << std::endl;
    replacer(input1);
    std::cout << "output1: " << input1 << std::endl;

    std::cout << "input2: " << input2 << std::endl;
    replacer(input2);
    std::cout << "output2: " << input2 << std::endl;

    return 0;
}
