class Node
{
public:
    int value;
    Node* next;
    
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value);

    ~LinkedList();

    void printList();

    Node* getHead();

    Node* getTail();

    int getLength();

    void toString();

    void append(int value);

    void removeLast();

    void prepend(int value);

    void removeFirst();

    Node* get(int index);

    bool set(int index, int value);

    bool insert(int index, int value);

    void deleteNode(int index);

    void reverse();
};