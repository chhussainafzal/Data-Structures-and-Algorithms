#include "balance_brackets.h"

bool balanceBrackets(const std::string& equation) {
    std::stack<char> bracketStack;

    for (char c : equation) {
        if (c == '(' || c == '[' || c == '{') {
            bracketStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (bracketStack.empty()) {
                return false;
            }

            char topBracket = bracketStack.top();
            bracketStack.pop();

            if (c == ')' && topBracket != '(' ||
                c == ']' && topBracket != '[' ||
                c == '}' && topBracket != '{') {
                return false;
            }
        }
    }

    return bracketStack.empty();
}
