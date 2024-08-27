#include <iostream>
#include "Stack.h"

bool isLetterOrDigit(const char character) {
    static constexpr char ALPHABET[26] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    static constexpr char DIGITS[10] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (char c : ALPHABET) {
        if (character == c || character == (c - 32)) {
            return true;
        }
    }

    for (char c : DIGITS) {
        if (character == c) {
            return true;
        }
    }

    return false;
}

template<typename T>
void populate(Stack<T>& stack, const char* cptr) {
    while (*cptr != '\0') {
        if (isLetterOrDigit(*cptr)) {
            stack.push(*cptr);
        }
        ++cptr;
    }
}

template<typename T>
bool isPalindrome(Stack<T>& stack, const char* word) {
    char stackLetter{};
    while (*word != '\0') {
        stack.pop(stackLetter);

        if (stackLetter != *word) {
            return false;
        }
        
        ++word;
    }

   return stack.isStackEmpty();
}

int main() {
    char word1[] {"racecar"};
    Stack<char> wordLetters{};

    std::cout << std::boolalpha;

    populate(wordLetters, word1);
    std::cout << "word: " << word1 << "\npalindrome: " << isPalindrome(wordLetters, word1) <<  "\n\n";

    char word2[] {",.race car';"};
    populate(wordLetters, word2);
    std::cout << "word: " << word2 << "\npalindrome: " << isPalindrome(wordLetters, word1) << "\n\n";

    char word3[] {"example"};
    populate(wordLetters, word3);
    std::cout << "word: " << word3 << "\npalindrome: " << isPalindrome(wordLetters, word3) << "\n\n";

    return 0;
}