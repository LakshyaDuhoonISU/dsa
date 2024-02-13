// create a linked list and search an element
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
    int n, count = 0;
    cout << "Enter number of nodes:";
    cin >> n;
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *nextNode = new Node();
        if (start == NULL)
        {
            start = nextNode;
            ptr = start;
        }
        else
        {
            ptr->next = nextNode;
            ptr = nextNode;
        }
        count++;
    }
    cout << "Number of nodes: " << count << endl;
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    ptr = start;
    Node *pos = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            pos = ptr;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    if (pos != NULL)
    {
        cout << "Element found at " << pos << endl;
    }
    else
    {
        cout << "No element found" << endl;
    }
    delete start;
    return 0;
}