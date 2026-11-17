#include <iostream>

#include "Stack.h"

int main()
{   
    Stack* myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();
    myStack->toString();

    myStack->push(5);
    myStack->push(8);
    myStack->toString();

    int val = myStack->pop();
    std::cout << "Popped value: " << val << std::endl;
    myStack->toString();

    return 0;
}