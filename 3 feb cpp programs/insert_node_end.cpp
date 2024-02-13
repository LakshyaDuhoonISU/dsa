// insert node at end of linked list
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
    cout << "Enter number of nodes: ";
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
    Node *next_node = new Node();
    if (next_node == NULL)
    {
        cout << "Overflow" << endl;
        return 0;
    }
    else
    {
        count++;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = next_node;
    ptr = start;
    while (ptr != NULL)
    {
        cout <<"Node data: "<< ptr->data << endl;
        ptr = ptr->next;
    }
    cout << "Number of nodes: " << count << endl;
    delete start;
    return 0;
}