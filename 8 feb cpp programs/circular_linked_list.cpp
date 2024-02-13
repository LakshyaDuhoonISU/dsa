//demonstration of circular linked list
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
    cout<<"Circular linked list: "<<endl;
    while (preptr->next!=start)
    {
        cout<<ptr->data<<endl;
        preptr=ptr;
        ptr=ptr->next;
    }
    return 0;
}