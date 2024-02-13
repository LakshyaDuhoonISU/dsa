//insert node at beginning of circular linked list
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next=NULL;
    }
};

int main()
{
    Node *n1=new Node(10);
    Node *start=n1;
    Node *n2=new Node(20);
    n1->next=n2;
    Node *n3=new Node(30);
    n2->next=n3;
    n3->next=start;
    Node *ptr=start;
    Node *preptr=ptr;
    cout<<"Before insertion: "<<endl;
    while (preptr->next!=start)
    {
        cout<<ptr->data<<endl;
        preptr=ptr;
        ptr=ptr->next;
    }
    Node *n4=new Node(40);
    n4->next=start;
    ptr=start;
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=n4;
    start=n4;
    ptr=start;
    preptr=ptr;
    cout<<"After insertion: "<<endl;
    while (preptr->next!=start)
    {
        preptr=ptr;
        cout<<preptr->data<<endl;
        ptr=ptr->next;
    }
    return 0;
}