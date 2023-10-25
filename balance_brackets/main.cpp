#include <iostream>
#include <string>
#include "balance_brackets.h"

int main() {
    std::string equation;
    std::cout << "Enter an equation: ";
    std::cin >> equation;

    bool isBalanced = balanceBrackets(equation);

    if (isBalanced) {
        std::cout << "The equation is balanced." << std::endl;
    }
    else {
        std::cout << "The equation is not balanced." << std::endl;
    }

    return 0;
}