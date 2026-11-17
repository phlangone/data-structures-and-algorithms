#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    cout << boolalpha;

    BinarySearchTree bst;

    for (int value : {47, 21, 76, 18, 52, 82, 27}) {
        bst.insert(value);
    }

    // Leaf node
    cout << "Remove 18: " << bst.remove(18) << endl;
    cout << "Contains 18: " << bst.contains(18) << endl;

    // One child
    cout << "Remove 21: " << bst.remove(21) << endl;
    cout << "Contains 27: " << bst.contains(27) << endl;

    cout << "Remove 52: " << bst.remove(52) << endl;
    cout << "Remove 76: " << bst.remove(76) << endl;
    cout << "Contains 82: " << bst.contains(82) << endl;

    // Nonexistent node
    cout << "Remove 99: " << bst.remove(99) << endl;

    // Root with one child
    BinarySearchTree bst2;

    bst2.insert(47);
    bst2.insert(21);

    cout << "Remove root 47: " << bst2.remove(47) << endl;
    cout << "New root: " << bst2.getRoot()->value << endl;

    // Root without children
    BinarySearchTree bst3;

    bst3.insert(47);

    cout << "Remove root 47: " << bst3.remove(47) << endl;
    cout << "Empty tree: " << (bst3.getRoot() == nullptr) << endl;

    // Two children - successor is a leaf
    BinarySearchTree bst4;

    for (int value : {47, 21, 76, 18, 27}) {
        bst4.insert(value);
    }

    cout << "\nTwo children (21):" << endl;
    cout << "Remove 21: " << bst4.remove(21) << endl;
    cout << "Contains 21: " << bst4.contains(21) << endl;
    cout << "Contains 18: " << bst4.contains(18) << endl;
    cout << "Contains 27: " << bst4.contains(27) << endl;

    // Two children - successor has right child
    BinarySearchTree bst5;

    for (int value : {47, 21, 76, 18, 27, 52, 82, 60}) {
        bst5.insert(value);
    }

    cout << "\nTwo children (root):" << endl;
    cout << "Remove 47: " << bst5.remove(47) << endl;

    if (auto* root = bst5.getRoot(); root) {
        cout << "New root: " << root->value << endl;
    }

    cout << "Contains 47: " << bst5.contains(47) << endl;
    cout << "Contains 52: " << bst5.contains(52) << endl;
    cout << "Contains 60: " << bst5.contains(60) << endl;

    if (auto* node = bst5.find(76); node && node->left) {
        cout << "Left child of 76: " << node->left->value << endl;
    }

    // Test in-order print
    BinarySearchTree bst6;

    for (int value : {47, 21, 76, 18, 52, 82, 27, 10, 35}) {
        bst6.insert(value);
    }

    cout << "\nIn-order: ";
    bst6.print();
    cout << endl;    

    return 0;
}