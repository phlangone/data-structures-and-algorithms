#pragma once

#include "Product.h"

class Node
{
public:
    Product product;
    Node* next;
    Node* prev;

    Node(const Product& product) : product(product)
    {
        next = nullptr;
        prev = nullptr;
    }
};