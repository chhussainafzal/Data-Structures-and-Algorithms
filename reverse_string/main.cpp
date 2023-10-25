#include <iostream>
#include "reverse_string.h"

int main() {
    std::string s = "Hello World";
    std::string reversedString = reverseStringUsingStack(s);
    std::cout << "Reversed string: " << reversedString << std::endl;
    return 0;
}