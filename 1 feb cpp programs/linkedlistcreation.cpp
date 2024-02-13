// creation of linked list using class and struct
#include <iostream>
#include<string>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void countNodes(Node *start) //Node *start points to the start of the list which contains the address of first node in the linked list
{
    int count=0;
    Node *ptr=start; //Node *ptr points to the start of the linked list which contains the address of first node in the linked list
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    cout<<"Number of nodes: "<<count<<endl;
}

int main()
{
    Node *start;
    Node *n1=(Node *)malloc(sizeof(Node));
    start=n1;
    n1->data=33;
    n1->next=NULL;
    Node *n2=new Node();
    n1->next=n2;
    n2->data=48;
    n2->next=NULL;
    Node *n3=new Node();
    n2->next=n3;
    n3->data=51;
    n3->next=NULL;
    for (Node *ptr = start; ptr != NULL; ptr=ptr->next)
    {
        cout << ptr->data << endl;
    }
    countNodes(start);
    delete(start);
    return 0;
}