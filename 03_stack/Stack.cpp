#include <iostream>
#include <climits>

#include "Stack.h"

Stack::Stack(int value)
{
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
}

Node* Stack::getTop() {
    return this->top;
}

int Stack::getHeight() {
    return this->height;
}

void Stack::printStack() {
    Node* temp = top;

    while(temp) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

void Stack::toString()
{
    // Top
   if(getTop() != nullptr) {
        std::cout << "Top: " << getTop()->value << std::endl;
   } 
   else {
        std::cout << "Top: nullptr" << std::endl;
   }

   // Height
   std::cout << "Height: " << height << std::endl;

   // Stack
   std:: cout << "Stack: ";
   printStack();

   std::cout << "================" << std::endl;    
}

void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}

int Stack::pop()
{
    if (height == 0) {
        return INT_MIN;
    }

    Node* temp = top;
    int poppedValue = top->value;
    top = top->next;
    delete temp;
    height--;

    return poppedValue;
}