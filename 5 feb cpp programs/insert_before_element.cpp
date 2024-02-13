// insert a node before an element having a value num
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
    Node *preptr = ptr;
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
    int a;
    cout << "Enter element to add a node before it: ";
    cin >> a;
    Node *new_node = new Node();
    ptr = start;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        while (ptr->data != a)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "No element found" << endl;
        }
        else
        {
            preptr->next = new_node;
            new_node->next = ptr;
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