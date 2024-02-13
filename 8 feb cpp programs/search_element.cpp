//search for an element in the circular list
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
    int element;
    cout<<"Enter element to search: ";
    cin>>element;
    Node *n1=new Node(10);
    Node *start=n1;
    Node *n2=new Node(20);
    n1->next=n2;
    Node *n3=new Node(30);
    n2->next=n3;
    n3->next=start;
    Node *ptr=start;
    Node *preptr=ptr;
    Node *temp=NULL;
    while (preptr->next!=start)
    {
        if (ptr->data==element)
        {
            cout<<"Element "<<ptr->data<<" found at "<<ptr<<endl;
            temp=ptr;
            break;
        }
        preptr=ptr;
        ptr=ptr->next;
    }
    if (temp==NULL)
    {
        cout<<"No element found"<<endl;
    }
    ptr=start;
    preptr=ptr;
    cout<<"List: "<<endl;
    while (preptr->next!=start)
    {
        preptr=ptr;
        cout<<preptr->data<<endl;
        ptr=ptr->next;
    }
    return 0;
}