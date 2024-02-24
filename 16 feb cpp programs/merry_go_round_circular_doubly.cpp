// merry go round simulator using circular doubly linked list(user name, no of rides)
#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int rides;
    Node *prev;
    Node *next;
    Node()
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number of rides: ";
        cin >> rides;
        while (rides <= 0)
        {
            cout << "Enter valid number of rides: ";
            cin >> rides;
        }
        prev = NULL;
        next = NULL;
    }
};

Node *createList(int n)
{
    Node *start = NULL;
    Node *ptr = NULL;
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
            newnode->prev = ptr;
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    ptr->next = start;
    start->prev = ptr;
    return start;
}

void deleteList(Node *&a)
{
    Node *ptr = a;
    Node *temp = ptr;
    if (a == NULL)
    {
        return;
    }
    do
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    } while (ptr != a);
    a = NULL;
}

void merry(Node *&a)
{
    int n = 1;
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Empty list(Underflow)";
        return;
    }
    else
    {
        do
        {
            ptr->rides--;
            if (ptr->rides <= 0)
            {
                cout << "User " << ptr->name << " rides are over." << endl;
                if (ptr == a && ptr->next == a)
                {
                    delete ptr;
                    a = NULL;
                    return;
                }
                else if (ptr == a)
                {
                    Node *temp = ptr;
                    ptr = ptr->next;
                    ptr->prev = a->prev;
                    a->prev->next = ptr;
                    a = ptr;
                    delete temp;
                }
                else
                {
                    Node *temp = ptr;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    ptr = ptr->next;
                    delete temp;
                }
            }
            else
            {
                ptr = ptr->next;
            }
            if (ptr == a)
            {
                Node *preptr = a;
                cout << "\nRound " << n << ":\n";
                do
                {
                    cout << "User " << preptr->name << " rides left: " << preptr->rides << endl;
                    preptr = preptr->next;
                } while (preptr != a);
                n++;
            }
        } while (a != NULL);
    }
}

int main()
{
    int n;
    cout << "Enter number of total users: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Invalid number. Please enter appropriate number: ";
        cin >> n;
    }
    Node *start = createList(n);
    merry(start);
    deleteList(start);
    return 0;
}