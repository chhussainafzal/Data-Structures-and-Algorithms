

#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int max_size;
    int top;
    int* array;

public:
    Stack(int size);
    ~Stack();
    bool IsEmpty();
    bool IsFull();
    void Push(int value);
    void Pop();
};

#endif


