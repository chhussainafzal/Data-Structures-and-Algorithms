#include "stack.h"

void Stack::push(char item) {
    stackVector.push_back(item);
}

char Stack::pop() {
    if (isEmpty()) {
        return '\0'; 
    }
    char poppedItem = stackVector.back();
    stackVector.pop_back();
    return poppedItem;
}

bool Stack::isEmpty() {
    return stackVector.empty();
}