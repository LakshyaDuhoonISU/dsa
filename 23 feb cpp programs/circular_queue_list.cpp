// circular queue menu driven program(linked list)
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

void enqueue(Node *&front, Node *&rear)
{
    Node *newnode = new Node();
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
        rear->next = front;
    }
    else // insertion at end
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    cout << "Element added successfully.\n";
}

void dequeue(Node *&front, Node *&rear)
{
    Node *temp = NULL;
    if (front == NULL)
    {
        cout << "Queue is empty. Cannot delete elements.\n";
    }
    else
    {
        if (front->next == front) // if only one node is present
        {
            cout << "Element " << front->data << " deleted successfully.\n";
            temp = front;
            front = NULL;
            rear = NULL;
        }
        else // deletion at beginning
        {
            temp = front;
            front = front->next;
            rear->next = front;
            cout << "Element " << temp->data << " deleted successfully.\n";
        }
        delete temp;
    }
}

void peek(Node *&front)
{
    if (front == NULL)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        cout << "Top element: " << front->data << endl;
    }
}

void deleteList(Node *&front, Node *&rear)
{
    Node *temp = NULL;
    Node *ptr = front;
    if (front == NULL)
    {
        return;
    }
    else
    {
        while (ptr->next != front)
        {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    front = NULL;
    rear = NULL;
}

void showList(Node *&front, Node *&rear)
{
    Node *ptr = front;
    if (front == NULL)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        while (ptr->next != front)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}

int main()
{
    int choice;
    Node *front = NULL;
    Node *rear = NULL;
    while (true)
    {
        cout << "\nCircular queue operations:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n5.Show Queue\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue(front, rear);
            break;
        case 2:
            dequeue(front, rear);
            break;
        case 3:
            peek(front);
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        case 5:
            showList(front, rear);
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
    deleteList(front, rear);
    return 0;
}