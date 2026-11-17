#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{   
    Queue* myQueue = new Queue(4);
    myQueue->toString();

    myQueue->enqueue(5);
    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->toString();

    cout << "Value: " << myQueue->dequeue() << endl;
    cout << "Value: " << myQueue->dequeue() << endl;
    myQueue->toString();
    cout << "Value: " << myQueue->dequeue() << endl;
    cout << "Value: " << myQueue->dequeue() << endl;
    myQueue->toString();

    cout << "Value: " << myQueue->dequeue() << endl;
    myQueue->toString();

    delete myQueue;

    return 0;
}