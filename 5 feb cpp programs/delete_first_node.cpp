//deletion of first node in linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        cout << "Enter data: ";
        cin >> data;
        next = NULL;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *start = NULL;
    Node *ptr = start;
    Node *preptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node();
        if (start == NULL)
        {
            start = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    ptr = start;
    if (start == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        start=ptr->next;
        delete ptr;
    }
    preptr = start;
    while (preptr != NULL)
    {
        cout << preptr->data << endl;
        preptr = preptr->next;
    }
    return 0;
}