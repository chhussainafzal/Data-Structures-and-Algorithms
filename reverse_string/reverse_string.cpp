#include "reverse_string.h"

std::string reverseStringUsingStack(const std::string& s) {
    Stack stack;
    for (char c : s) {
        stack.push(c);
    }
    std::string reversedString;
    while (!stack.isEmpty()) {
        reversedString += stack.pop();
    }
    return reversedString;
}
