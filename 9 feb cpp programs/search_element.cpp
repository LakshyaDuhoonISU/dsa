// search for an element in a doubly linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *start;
    Node *n1 = new Node(10);
    start = n1;
    Node *n2 = new Node(20);
    n1->next = n2;
    n2->prev = n1;
    Node *n3 = new Node(30);
    n2->next = n3;
    n3->prev = n2;
    Node *n4 = new Node(40);
    n3->next = n4;
    n4->prev = n3;
    Node *n5 = new Node(50);
    n4->next = n5;
    n5->next = NULL;
    n5->prev = n4;
    Node *ptr = start;
    int element=40;
    while (ptr->data != element)
    {
        ptr=ptr->next;
    }
    cout<<"Element "<<ptr->data<<" found at "<<ptr<<endl;
    ptr=start;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    return 0;
}