
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

class Stack {
private:
    Node* top;
    int height;

public:
    Stack(int value);

    Node* getTop();

    int getHeight();

    void printStack();

    void toString();

    void push(int value);

    int pop();
};