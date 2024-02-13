// // delete a node after a particular element
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
    Node *preptr = start;
    Node *temp = NULL;
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
    cout << "Enter element to delete node after: ";
    cin >> a;
    ptr = start;
    if (start == NULL)
    {
        cout << "Underflow" << endl;
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
            cout << "Element not found" << endl;
        }
        else
        {
            //temp = ptr;
            if (ptr->next == NULL)
            {
                cout << "No element to delete" << endl;
            }
            else
            {
                preptr = ptr;
                temp = ptr->next;
                preptr->next = temp->next;
                delete temp;
            }
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