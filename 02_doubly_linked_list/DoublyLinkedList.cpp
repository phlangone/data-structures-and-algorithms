#include <iostream>

#include "DoublyLinkedList.h"

/**
 * Class constructor
 */
DoublyLinkedList::DoublyLinkedList(int value)
{
    // Create first node
    auto node = new Node(value);

    // Update head and tail
    head = node;
    tail = node;

    // Update lenght
    length = 1;
}

/**
 * Class destructor
 */
DoublyLinkedList::~DoublyLinkedList()
{
    // Delete objects from ll
    auto node = head;

    while(head)
    {
        head = head->next;
        delete node;
        node = head;
    }

    // Clean attributes
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/**
 * Print each element value
 */
void DoublyLinkedList::printList()
{
    // Iterate printing values
    auto node = head;

    while(node)
    {
        std::cout << node->value << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

/**
 * Getters
 */
Node* DoublyLinkedList::getHead() {
    return this->head;
}

Node* DoublyLinkedList::getTail() {
    return this->tail;
}

int DoublyLinkedList::getLength() {
    return this->length;
}

/**
 * ToString method
 */
void DoublyLinkedList::toString()
{
    // Head
   if(getHead() != nullptr) {
        std::cout << "Head: " << getHead()->value << std::endl;
   } 
   else {
        std::cout << "Head: nullptr" << std::endl;
   }

   // Tail
   if(getTail() != nullptr) {
        std::cout << "Tail: " << getTail()->value << std::endl;
   } 
   else {
        std::cout << "Tail: nullptr" << std::endl;
   }
   
   // Lenght
   std::cout << "Length: " << length << std::endl;

   // List
   std:: cout << "List: ";
   printList();

   std::cout << "================" << std::endl;
}

/**
 * Add element at the end of dll
 */
void DoublyLinkedList::append(int value)
{
    auto newNode = new Node(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

/**
 * Delete element at the end of dll
 */
void DoublyLinkedList::removeLast()
{
    auto temp = tail;

    if (length == 0) {
        return;
    } else if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = temp->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

/**
 * Add element at the begining of dll
 */
void DoublyLinkedList::prepend(int value)
{
    auto newNode = new Node(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

/**
 * Remove first element of dll
 */
void DoublyLinkedList::removeFirst()
{
    auto temp = head;

    if (length == 0) {
        return;
    }
    else if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}

/** 
 * Get node by index
 */
Node* DoublyLinkedList::get(int index)
{
    auto temp = head;
    int half = length / 2;

    if (index < 0 || index >= length) {
        return nullptr;
    } 

    // Forward
    if (index <= half) {
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    } 
    
    // Backward
    else {
        temp = tail;
        for (int i = length - 1; i > index; i--) {
            temp = temp->prev;
        }
    }

    return temp;
}

/**
 * Set node value by index
 */
bool DoublyLinkedList::set(int index, int value)
{
    auto temp = get(index);

    if (temp) {
        temp->value = value;
        return true;
    }

    return false;
}

/**
 * Insert node at index
 */
bool DoublyLinkedList::insert(int index, int value)
{
    if (index < 0 || index > length) {
        return false;
    }
    else if (index == 0) {
        prepend(value);
    } else if (index == length) {
        append(value);
    } else {
        auto newNode = new Node(value);
        auto before = get(index-1);
        auto after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
    }
    return true;
}

/**
 * Delete node at index
 */
void DoublyLinkedList::deleteNode(int index)
{
    if (index < 0 || index >= length) {
        return;
    }

    if (index == 0) {
        removeFirst();
        return;
    }

    if (index == length - 1) {
        removeLast();
        return;
    }

    auto node = get(index);
    auto after = node->next;
    auto before = node->prev;

    after->prev = before;
    before->next = after;

    length--;
    delete node;
}