#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
private:
    std::vector<char> stackVector;

public:
    void push(char item);
    char pop();
    bool isEmpty();
};

#endif 
