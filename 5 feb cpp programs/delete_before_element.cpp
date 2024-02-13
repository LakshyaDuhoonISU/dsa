// deletion of node before a given element
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
    Node *temp = start;
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
    int a;
    cout << "Enter element to delete a node before: ";
    cin >> a;
    if (start == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        while (ptr->data != a)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (preptr == start)
            {
                start = ptr;
            }
            else
            {
                temp->next = ptr;
            }
            delete preptr;
        }
    }
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    return 0;
}