#include <iostream>

#include "LinkedList.h"

int main()
{
    LinkedList* ll = new LinkedList(4);

    ll->toString();

    ll->append(6);
    ll->append(8);

    ll->toString();

    ll->removeLast();

    ll->toString();

    ll->removeLast();

    ll->toString();

    ll->removeLast();

    ll->toString();

    ll->append(5);

    ll->append(10);

    ll->toString();

    ll->prepend(7);

    ll->prepend(2);

    ll->toString();

    ll->removeFirst();

    ll->toString();

    ll->removeFirst();

    ll->toString();

    ll->append(5);
    ll->append(3);

    ll->toString();

    for (int i = 0; i < ll->getLength(); i++) {
        std::cout << ll->get(i)->value << std::endl;
    }

    for (int i = 0; i < ll->getLength(); i++) {
        ll->set(i, i);
    }    

    ll->toString();

    ll->insert(2, 77);

    ll->toString();

    //ll->deleteNode(2);

    //ll->toString();

    //ll->deleteNode(0);
    
    //ll->toString();

    //ll->deleteNode(1);

    //ll->toString();

    ll->reverse();

    ll->toString();

    delete ll;
    
    return 0;
}