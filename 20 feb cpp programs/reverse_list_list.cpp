// reversing a list using stack (linked list)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *createList(int n)
{
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node();
        cout << "Enter data: ";
        cin >> newnode->data;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    return start;
}

void reverseList(Node *&a)
{
    Node *top = NULL;
    Node *temp=NULL;
    Node *ptr = a;
    while (ptr != NULL)
    { 
        Node *nn=new Node();
        nn->next=NULL;
        nn->data = ptr->data;
        if (top == NULL)
        {
            top = nn;
            temp=nn;
        }
        else
        {
            top=nn;
            nn->next=temp;
            temp=nn;           
        }
        ptr = ptr->next;
    }
    ptr=a;
    temp=top;
    cout<<"List: ";
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\nStack: ";
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    temp=top;
    ptr=a;
    while (temp!=NULL)
    {
        ptr->data=temp->data;
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr=a;
    cout<<"\nReversed list: ";
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void deleteList(Node *&a)
{
    Node *ptr = a;
    Node *temp = ptr;
    if (a == NULL)
    {
        return;
    }
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    a = NULL;
}

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    Node *start=createList(n);
    reverseList(start);
    deleteList(start);
    return 0;
}