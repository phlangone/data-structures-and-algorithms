#include <iostream>

#include "LinkedList.h"

/**
 * Class constructor
 */
LinkedList::LinkedList(int value)
{
    // Create first node
    Node* node = new Node(value);

    // Update head and tail
    head = node;
    tail = node;

    // Update lenght
    length = 1;
}

/**
 * Class destructor
 */
LinkedList::~LinkedList()
{
    // Delete objects from ll
    Node* node = head;

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
void LinkedList::printList()
{
    // Iterate printing values
    Node* node = head;

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
Node* LinkedList::getHead() {
    return this->head;
}

Node* LinkedList::getTail() {
    return this->tail;
}

int LinkedList::getLength() {
    return this->length;
}

/**
 * ToString method
 */
void LinkedList::toString()
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
 * Add element at the end of ll
 */
void LinkedList::append(int value)
{
    // Create new node
    Node* newNode = new Node(value);

    // If ll is empty
    if (length == 0) {
        // Head and tail points to newNode;
        head = newNode;
        tail = newNode;
    } else {
        // Append node and update tail
        tail->next = newNode;
        tail = newNode;
    }

    // Increment length
    length++;
}

/**
 * Delete element at the end of ll
 */
void LinkedList::removeLast()
{
    // LL is empty
    if (length == 0) {
        return;
    } 
    
    // LL has one element 
    else if (length == 1) {
        Node* node = head;
        delete node;
        head = nullptr;
        tail = nullptr;
    }

    // LL has more than one element
    else {
        // LL iterators
        Node* temp = head;
        Node* pre = nullptr;

        // Iterate until temp reaches tail
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }

        // Update tail
        tail = pre;
        tail->next = nullptr;

        // Delete previous tail
        delete temp;

    }

    // Decrement length
    length--;
}

/**
 * Add element at the begining of ll
 */
void LinkedList::prepend(int value)
{
    // Creates new node
    Node* newNode = new Node(value);

    // If ll is empty
    if (length == 0) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        // Update head and insert node
        newNode->next = head;
        head = newNode;
    }

    // Increment length
    length++;
}

/**
 * Remove first element of ll
 */
void LinkedList::removeFirst()
{
    Node* first = head;

    if (length == 0) {
        return;
    } else if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = first->next;
    }

    // Update length and delete node
    length--;
    delete first;
}

/** 
 * Get node by index
 */
Node* LinkedList::get(int index)
{
    Node* node = head;

    if (index < 0 || index >= length) {
        return nullptr;
    } 

    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return node;
}

/**
 * Set node value by index
 */
bool LinkedList::set(int index, int value)
{
    Node* node = get(index);

    if (node) {
        node->value = value;
        return true;
    } 
    
    return false;
}

/**
 * Insert node at index
 */
bool LinkedList::insert(int index, int value)
{
    if (index < 0 || index > length) {
        return false;
    } else if (index == 0) {
        prepend(value);
    } else if (index == length) {
        append(value);
    } else {
        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    return true;
}

/**
 * Delete node at index
 */
void LinkedList::deleteNode(int index)
{
    if (index < 0 || index >= length) {
        return;
    } else if (index == 0) {
        removeFirst();
    } else if (index == length - 1) {
        removeLast();
    } else {
        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }
}

/**
 * Reverse ll order
 */
void LinkedList::reverse()
{
    Node* temp = head;
    head = tail;
    tail = temp;

    Node* after = temp->next;
    Node* before = nullptr;

    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}