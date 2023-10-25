

#include "stack.h"

int main() {
    int stackSize = 3;
    Stack stack(stackSize);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    while (!stack.IsEmpty()) {
        stack.Pop();
    }

    return 0;
}
