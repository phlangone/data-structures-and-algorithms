#include <iostream>
#include <climits>

#include "Queue.h"

using namespace std;

Queue::Queue(int value) {
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length++;
}

Node* Queue::getFirst() {
    return first;
}

Node* Queue::getLast() {
    return last;
}

void Queue::printQueue() 
{
    auto temp = first;

    while(temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}

void Queue::toString() {

    // First
    if (getFirst()) {
        cout << "First: " << getFirst()->value << endl;
    } else {
        cout << "First: nullptr" << endl;
    }

    // Last
    if (getLast()) {
        cout << "Last: " << getLast()->value << endl;
    } else {
        cout << "Last: nullptr" << endl;
    }    

    // Length
    cout << "Length: " << length << endl;

    // Queue
    cout << "Queue: " << endl;
    printQueue();

    cout << "================" << endl;
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node(value);

    if (length == 0) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

int Queue::dequeue() 
{
    if (length == 0) {
        return INT_MIN;
    }

    auto temp = first;
    int value = temp->value;

    if (length == 1) {
        first = nullptr;
        last = nullptr;
    } else {
        first = first->next;
    }
    
    delete temp;
    length--;

    return value;
}