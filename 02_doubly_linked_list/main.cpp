#include <iostream>

#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->toString();

    // append test
    myDLL->append(5);
    myDLL->append(3);
    myDLL->toString();

    // removeLast test
    myDLL->removeLast();
    myDLL->toString();
    myDLL->removeLast();
    myDLL->toString();
    myDLL->removeLast();
    myDLL->toString();
    myDLL->removeLast();
    myDLL->toString();

    // prepend test
    myDLL->prepend(4);
    myDLL->prepend(5);
    myDLL->prepend(2);
    myDLL->toString();

    // removeFirst test
    myDLL->removeFirst();
    myDLL->toString();
    myDLL->removeFirst();
    myDLL->toString();

    // get test
    myDLL->append(6);
    myDLL->append(7);
    myDLL->append(8);
    myDLL->toString();
    for (int i = 0; i < myDLL->getLength(); i++) {
        std::cout << myDLL->get(i)->value << std::endl;
    }

    // set test
    for (int i = 0; i < myDLL->getLength(); i++) {
        myDLL->set(i, i);
    }    
    myDLL->toString();

    // insert test
    myDLL->insert(2, 77);
    myDLL->toString();

    // delete test
    myDLL->deleteNode(2);
    myDLL->toString();
    
    return 0;
}