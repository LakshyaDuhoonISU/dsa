// menu driven doubly linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        cout << "Enter data: ";
        cin >> data;
        next = NULL;
        prev = NULL;
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
            ptr = newnode;
        }
    }
    return start;
}

void insertAtStart(Node *&a)
{
    Node *newnode = new Node();
    if (newnode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        if (a == NULL)
        {
            newnode->next = NULL;
            a = newnode;
        }
        else
        {
            newnode->next = a;
            a->prev = newnode;
            a = newnode;
        }
    }
}

void insertAtEnd(Node *&a)
{
    Node *ptr = a;
    Node *newnode = new Node();
    if (newnode == NULL)
    {
        cout << "Overflow" << endl;
    }
    else if (a == NULL)
    {
        newnode->next = NULL;
        a = newnode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->prev = ptr;
        ptr->next = newnode;
    }
}

void insertAfterElement(Node *&a)
{
    int n;
    cout << "Enter element after which to add a node: ";
    cin >> n;
    Node *new_node = new Node();
    Node *ptr = a;
    Node *preptr = ptr;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        while (preptr->data != n)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "No element found" << endl;
        }
        else if (ptr == a)
        {
            new_node->next = ptr->next;
            new_node->prev = a;
            a->next = new_node;
        }
        else
        {
            new_node->next = ptr;
            new_node->prev = preptr;
            preptr->next = new_node;
            ptr->prev = new_node;
        }
    }
}

void insertBeforeElement(Node *&a)
{
    Node *ptr = a;
    Node *preptr = ptr;
    int b;
    cout << "Enter element to add a node before it: ";
    cin >> b;
    Node *new_node = new Node();
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "No element found" << endl;
        }
        else if (ptr == a)
        {
            new_node->next = ptr;
            new_node->prev = NULL;
            a = new_node;
        }
        else
        {
            preptr->next = new_node;
            new_node->prev = preptr;
            new_node->next = ptr;
            ptr->prev = new_node;
        }
    }
}

void searchElement(Node *&a)
{
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    Node *ptr = a;
    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            cout << "Element " << ptr->data << " found at " << ptr << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Element not found" << endl;
}

void deleteFirstNode(Node *&a)
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Undeflow" << endl;
        return;
    }
    else
    {
        a = ptr->next;
        if (a != NULL)
        {
            a->prev = NULL;
        }
        delete ptr;
    }
}

void deleteLastNode(Node *&a)
{
    Node *ptr = a;
    Node *preptr = a;
    if (a == NULL)
    {
        cout << "Undeflow" << endl;
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        delete ptr;
    }
}

void deleteAfterElement(Node *&a)
{
    Node *ptr = a;
    Node *preptr = a;
    Node *temp = NULL;
    int b;
    cout << "Enter element to delete node after: ";
    cin >> b;
    ptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (ptr == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (ptr->next == NULL)
            {
                cout << "No element to delete" << endl;
            }
            else
            {
                preptr = ptr;
                temp = ptr->next;
                preptr->next = temp->next;
                temp->next->prev = preptr;
                delete temp;
            }
        }
    }
}

void deleteBeforeElement(Node *&a)
{
    Node *ptr = a;
    Node *preptr = NULL;
    Node *temp = a;
    int b;
    cout << "Enter element to delete a node before it: ";
    cin >> b;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (preptr == NULL) // if first node is selected, print error message
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (preptr == a)
            {
                a = ptr;
                ptr->prev = NULL;
            }
            else
            {
                temp->next = ptr;
                ptr->prev = temp;
            }
            delete preptr;
        }
    }
}

void showList(Node *&a)
{
    Node *ptr = a;
    Node *preptr = ptr;
    int choice;
    do
    {
        int count = 0;
        cout << "1. Print list in original order\n2. Print list in reverse order\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ptr = a;
            while (ptr != NULL)
            {
                count++;
                preptr = ptr;
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
            cout << "Number of nodes: " << count << endl;
            break;
        case 2:
            ptr = a;
            while (ptr != NULL)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            while (preptr != NULL)
            {
                count++;
                cout << preptr->data << endl;
                preptr = preptr->prev;
            }
            cout << "Number of nodes: " << count << endl;
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);
}

void deleteList(Node *&a)
{
    Node *ptr = a;
    Node *temp = ptr;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        delete temp;
        temp = ptr;
    }
    a = NULL;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *start = createList(n);
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Insert a node at beginning\n2.Insert a node at end\n3.Search the list for an element\n4.Insert a node after an element\n5.Insert a node before an element\n6.Delete first node\n7.Delete last node\n8.Delete a node after a particular element\n9.Delete a node before a particular element\n10.Show list\n11.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertAtStart(start);
            break;
        case 2:
            insertAtEnd(start);
            break;
        case 3:
            searchElement(start);
            break;
        case 4:
            insertAfterElement(start);
            break;
        case 5:
            insertBeforeElement(start);
            break;
        case 6:
            deleteFirstNode(start);
            break;
        case 7:
            deleteLastNode(start);
            break;
        case 8:
            deleteAfterElement(start);
            break;
        case 9:
            deleteBeforeElement(start);
            break;
        case 10:
            showList(start);
            break;
        case 11:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    deleteList(start);
    return 0;
}