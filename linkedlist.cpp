#include <iostream>
using namespace std;

// class Node
// {

// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = nullptr;
//     }
// };

// int main()
// {

//     Node *first;
//     Node firstC(1);
//     first = &firstC;

//     // Node *first = new Node(1);
//     Node *second = new Node(2);

//     // puting next node adress
//     first->next = second;

//     // look the first node also put the adress of next node besides data
//     cout << first->next << " " << second << endl;

//     // Traverse and print the linked list
//     Node *current = first;
//     while (current != nullptr)
//     {
//         cout << current->data << " ";
//         current = current->next;
//     }

//     cout << endl;

//     return 0;
// }

// 👉👉👉👉👉👉👉👉 Insertion in head

// creating new node
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// traves the linked list
void print(Node *head)
{
    // Node *temp = head;
    while (head != nullptr)
    {
        cout << head->data << ",";
        head = head->next;
    }
}

// insert new node at head
void insertAtHead(Node *&head, int data)
{
    // Create a new node with the data you want to insert.
    Node *temp = new Node(data);

    // Set the next pointer of the new node to point to the current head of the linked list.
    temp->next = head;

    // Update the head of the linked list to point to the new node.
    head = temp;
}

// insert new node at tail
void insertAtTail(Node *&tail, int data)
{
    // 1. create new node
    Node *temp = new Node(data);

    // Check if the list is empty (tail is nullptr)
    if (tail == nullptr)
    {
        // If it's empty, make the new node both the head and the tail.
        tail = temp;
        return;
    }

    // 2. set the tail pointer to this newly created node
    tail->next = temp;
    // 3. now set the tail to the last node or newly created node
    tail = temp;
}

// insert new node in a given position

void insertAtMiddle(Node *&head, int position, int data)
{
    Node *temp = new Node(data);

    // Check if the position is valid.
    if (position <= 1)
    {
        // Insert at the beginning; update head pointer.
        temp->next = head;
        head = temp;
        return;
    }

    Node *current = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        current = current->next;
        cnt++;
    }

    temp->next = current->next;
    current->next = temp;

    // current->next = temp;
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main()
{

    Node *first = new Node(1);
    Node *head = first;

    // cout << "Before ";
    // // print(head);
    // cout << endl;
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    // cout << "After ";
    // print(head);
    // cout << endl;

    // // insert at tail
    Node *tail = first;
    insertAtTail(tail, 10);
    print(head); // 3,2,1,10
    cout << endl;

    // insert at middle

    insertAtMiddle(head, 2, 15);
    print(head);
    cout << endl;
    // insertAtTail(tail, 25);
    // print(head);

    // reverse

    head = reverseLinkedList(head);
    cout << "reverse ";
    print(head);
    cout << endl;

    return 0;
}