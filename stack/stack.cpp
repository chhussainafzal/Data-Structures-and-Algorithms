

#include "stack.h"
#include <iostream>

Stack::Stack(int size) {
    max_size = size;
    top = -1;
    array = new int[max_size];
}

Stack::~Stack() {
    delete[] array;
}

bool Stack::IsEmpty() {
    return top == -1;
}

bool Stack::IsFull() {
    return top == max_size - 1;
}

void Stack::Push(int value) {
    if (IsFull()) {
        std::cout << "Stack is full. Cannot push " << value << std::endl;
    }
    else {
        array[++top] = value;
        std::cout << value << " pushed to the stack." << std::endl;
    }
}

void Stack::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
    }
    else {
        std::cout << array[top--] << " popped from the stack." << std::endl;
    }
}
