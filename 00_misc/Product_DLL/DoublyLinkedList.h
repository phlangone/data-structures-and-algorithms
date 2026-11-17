#pragma once

#include <iostream>
#include <string>

#include "Node.h"
#include "Product.h"

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int length;

    Product* _search(int id)
    {
        auto temp = head;

        while(temp) {
            if(temp->product.getId() == id) {
                return &temp->product;
            }
            temp = temp->next;
        }
        return nullptr;
    }    

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~DoublyLinkedList() {
        auto temp = head;

        while(temp) {
            head = head->next;
            delete temp;
            temp = head;
        }

        head = nullptr;
        tail = nullptr;
        length = 0;
    }    

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;    

    void showList()
    {
        auto temp = head;

        while(temp) {
            temp->product.print();
            std::cout << "===============" << std::endl;
            temp = temp->next;
        }
    }

    void insert(const Product& product) 
    {
        auto newProduct = new Node(product);

        if (length == 0) {
            head = newProduct;
            tail = newProduct;
        } else {
            tail->next = newProduct;
            newProduct->prev = tail;
            tail = newProduct;
        }
        length++;
    }
    
    bool remove(int id)
    {
        if (length == 0) {
            return false;
        } 

        auto temp = head;

        while(temp) {
            auto before = temp->prev;
            auto after = temp->next;

            if (temp->product.getId() == id) {

                if (before) {
                    before->next = after;
                } else {
                    head = after;
                }
                
                if (after) {
                    after->prev = before;
                } else {
                    tail = before;
                }

                delete temp;
                length--;
                return true;
            }

            temp = temp->next;
        }     

        return false;

    }

    const Product* search(int id)
    {
        return _search(id);
    }

    bool update(int id, double price)
    {
        auto product = _search(id);

        if (!product) {
            return false;
        }

        product->setPrice(price);
        return true;
    }
};