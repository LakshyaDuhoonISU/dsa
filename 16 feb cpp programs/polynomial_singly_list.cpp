// polynomial equation addition and subtraction using singly linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int coefficient;
    int power;
    Node *next;
    Node()
    {
        cout << "Enter coefficient: ";
        cin >> coefficient;
        cout << "Enter power: ";
        cin >> power;
        next = NULL;
    }
};

Node *createEquation(int n, int k)
{
    Node *start = NULL;
    Node *ptr = NULL;
    cout << "\nEquation No: " << k << endl;
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
            ptr = ptr->next;
        }
    }
    return start;
}

void deleteEquation(Node *&a)
{
    Node *ptr = a;
    Node *temp = ptr;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    a = NULL;
}

void addEquations(Node *&a, Node *&b)
{
    Node *start1 = a;
    Node *start2 = b;
    Node *ptr = start1;
    Node *ptr2 = start2;
    Node *start3 = NULL;
    Node *ptr3 = start3;
    while (ptr != NULL && ptr2 != NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        if (ptr->power > ptr2->power)
        {
            newnode->power = ptr->power;
            newnode->coefficient = ptr->coefficient;
            ptr = ptr->next;
        }
        else if (ptr->power < ptr2->power)
        {
            newnode->power = ptr2->power;
            newnode->coefficient = ptr2->coefficient;
            ptr2 = ptr2->next;
        }
        else
        {
            newnode->power = ptr2->power;
            newnode->coefficient = ptr2->coefficient + ptr->coefficient;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        if (start3 == NULL)
        {
            start3 = newnode;
            ptr3 = newnode;
        }
        else
        {
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->coefficient = ptr->coefficient;
            newnode->power = ptr->power;
            ptr = ptr->next;
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    else if (ptr2 != NULL)
    {
        while (ptr2 != NULL)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->coefficient = ptr2->coefficient;
            newnode->power = ptr2->power;
            ptr2 = ptr2->next;
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    Node *temp = start3;
    cout << "Addition equation:\n";
    while (temp != NULL)
    {
        cout << "Coefficient: " << temp->coefficient << endl
             << "Power: " << temp->power << endl;
        temp = temp->next;
    }
    temp = start3;
    ptr = temp;
    while (temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
        delete ptr;
    }
    start3 = NULL;
}

void subtractEquations(Node *&a, Node *&b)
{
    Node *start1 = a;
    Node *start2 = b;
    Node *ptr = start1;
    Node *ptr2 = start2;
    Node *start3 = NULL;
    Node *ptr3 = start3;
    while (ptr != NULL && ptr2 != NULL)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        if (ptr->power > ptr2->power)
        {
            newnode->power = ptr->power;
            newnode->coefficient = ptr->coefficient;
            ptr = ptr->next;
        }
        else if (ptr->power < ptr2->power)
        {
            newnode->power = ptr2->power;
            newnode->coefficient = ptr2->coefficient;
            ptr2 = ptr2->next;
        }
        else
        {
            newnode->power = ptr2->power;
            newnode->coefficient = ptr2->coefficient - ptr->coefficient;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        if (start3 == NULL)
        {
            start3 = newnode;
            ptr3 = newnode;
        }
        else
        {
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->coefficient = ptr->coefficient;
            newnode->power = ptr->power;
            ptr = ptr->next;
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    else if (ptr2 != NULL)
    {
        while (ptr2 != NULL)
        {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->coefficient = ptr2->coefficient;
            newnode->power = ptr2->power;
            ptr2 = ptr2->next;
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
    }
    Node *temp = start3;
    cout << "Subtraction equation:\n";
    while (temp != NULL)
    {
        cout << "Coefficient: " << temp->coefficient << endl
             << "Power: " << temp->power << endl;
        temp = temp->next;
    }
    temp = start3;
    ptr = temp;
    while (temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
        delete ptr;
    }
    start3 = NULL;
}

int main()
{
    int a, b;
    cout << "Enter number of terms in first equation: ";
    cin >> a;
    while (a <= 0)
    {
        cout << "Invalid number of terms. Enter appropriate number of terms: ";
        cin >> a;
    }
    cout << "Enter number of terms in second equation: ";
    cin >> b;
    while (b <= 0)
    {
        cout << "Invalid number of terms. Enter appropriate number of terms: ";
        cin >> b;
    }
    Node *start1 = createEquation(a, 1);
    Node *start2 = createEquation(b, 2);
    int ch;
    char choice;
    do
    {
        cout << "1.Add equations\n2.Subtract equations\n3.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            addEquations(start1, start2);
            break;
        case 2:
            subtractEquations(start1, start2);
            break;
        case 3:
            cout << "Exiting...\n";
            deleteEquation(start1);
            deleteEquation(start2);
            return 0;
        default:
            cout << "Wrong choice\n";
            break;
        }
        cout << "Want to continue(y/n)?: ";
        cin >> choice;
    } while (tolower(choice) != 'n');
    deleteEquation(start1);
    deleteEquation(start2);
    return 0;
}