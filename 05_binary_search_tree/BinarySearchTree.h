#pragma once

#include <iostream>

class Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree
{
private:
    Node* root;

    // Remove leaf node or with one child
    bool _removeNode(Node* node, Node* parent) {

        if (!node || (node->left && node->right)) {
            return false;
        }        

        auto replacement = node->left ? node->left : node->right;

        if(!parent) {
            root = replacement;
        } else if (parent->left == node) {
            parent->left = replacement;
        } else if (parent->right == node) {
            parent->right = replacement;
        }
        
        delete node;
        return true;
    }

    // Print left, root and right at each node, recursively
    void _print(Node* node) {
        if(!node) {
            return;
        }
        _print(node->left);
        std::cout << node->value <<  " ";
        _print(node->right);
    }

public:
    BinarySearchTree() : root(nullptr){}
    BinarySearchTree(int value) {
        Node* newNode = new Node(value);
        root = newNode;        
    }

    const Node* getRoot() const {
        return root;
    }

    bool contains(int value) {

        if (!root) {
            return false;
        }

        auto temp = root;

        while (temp) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }

        return false;
    }

    Node* find(int value) const {
        if (!root) {
            return nullptr;
        }

        auto temp = root;

        while (temp) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return temp;
            }
        }

        return nullptr;        
    } 

    bool insert(int value) {
        auto newNode = new Node(value);

        if (!root) {
            root = newNode;
            return true;
        }

        auto temp = root;

        while(true) {

            if (newNode->value == temp->value) {
                delete newNode;
                return false;
            }

            if (newNode->value < temp->value) {
                if (!temp->left) {
                    temp->left = newNode;
                    return true;
                } else {
                    temp = temp->left;
                }
            }

            else if (newNode->value > temp->value) {
                if (!temp->right) {
                    temp->right = newNode;
                    return true;
                } else {
                    temp = temp->right;
                }
            }
        }       
    }

    bool remove(int value) {
        
        // Empty tree
        if (!root) {
            return false;
        }

        Node* temp = root;
        Node* parent = nullptr;
        
        // Find node and its parent
        while (temp && temp->value != value) {
            parent = temp;
            if (value < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            } 
        }

        // Contains
        if (!temp) {
            return false;
        }

        // Leaf node or with one child
        if (!temp->left || !temp->right) {
            return _removeNode(temp, parent);
        }

        // Node with two childs, needs to look for sucessor
        Node* successor = temp->right;
        Node* successorParent = temp;

        while(successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        temp->value = successor->value;
        return _removeNode(successor, successorParent);
    }

    void print() {
        _print(root);
    }
};