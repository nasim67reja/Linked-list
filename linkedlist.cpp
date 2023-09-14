#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};

int main()
{

    Node *first;
    Node firstC(1);
    first = &firstC;

    // Node *first = new Node(1);
    Node *second = new Node(2);

    // puting next node adress
    first->next = second;
    second->next = NULL;

    // look the first node also put the adress of next node besides data
    cout << first->next << " " << second << endl;

    return 0;
}