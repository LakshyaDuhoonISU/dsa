// Implement Library Catalog using singly linked list
// - Design a system to keep track of books in a library
// -Each node represents a book, and the linked list facilitates easy addition
// and removal of books.
// -Searching of a book by title / author name.

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string title;
    string author;
    Node *next;
    Node()
    {
        cout << "Enter book title: ";
        getline(cin >> ws, title);
        cout << "Enter author: ";
        getline(cin >> ws, author);
        next = NULL;
    }
};

Node *createLibrary(int n)
{
    Node *start = NULL;
    Node *ptr = start;
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

void showBooks(Node *&a)
{
    int count = 0;
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Empty library" << endl;
        return;
    }
    while (ptr != NULL)
    {
        cout << ptr->title << " by " << ptr->author << endl;
        count++;
        ptr = ptr->next;
    }
    cout << "Number of books: " << count << endl;
}

void addBook(Node *&a)
{
    Node *ptr = a;
    Node *newnode = new Node();
    if (newnode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    cout << "Book added successfully" << endl;
}

void removeBook(Node *&a)
{
    Node *ptr = a;
    Node *preptr = a;
    Node *temp = NULL;
    string name;
    if (a == NULL)
    {
        cout << "Library is empty" << endl;
        return;
    }
    cout << "Enter book name to remove: ";
    cin.ignore();
    getline(cin, name);
    if (a->title == name)
    {
        temp = a;
        a = a->next;
        delete temp;
        cout << "Book removed successfully" << endl;
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->title == name)
            {
                preptr->next = ptr->next;
                delete ptr;
                cout << "Book removed successfully" << endl;
                return;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "Book not found" << endl;
        }
    }
}

void searchBook(Node *&a)
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Library is empty" << endl;
        return;
    }
    int count = 0;
    int choice;
    string name;
    string author_name;
    b:
    cout << "1.Search by book name\n2.Search by author\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter book name to search: ";
        count=0;
        ptr=a;
        cin.ignore();
        getline(cin, name);
        while (ptr != NULL)
        {
            if (ptr->title == name)
            {
                cout << ptr->title << " by " << ptr->author << endl;
                count++;
            }
            ptr = ptr->next;
        }
        if (count == 0)
        {
            cout << "No books found" << endl;
        }
        break;
    case 2:
        count=0;
        ptr=a;
        cout << "Enter author name to search: ";
        cin.ignore();
        getline(cin, author_name);
        while (ptr != NULL)
        {
            if (ptr->author == author_name)
            {
                cout << ptr->title << " by " << ptr->author << endl;
                count++;
            }
            ptr = ptr->next;
        }
        if (count == 0)
        {
            cout << "No books found" << endl;
        }
        break;
    default:
        cout << "Invalid choice" << endl;
        goto b;
    }
}

void deleteList(Node *&a)
{
    Node *ptr = a;
    Node *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    a = NULL;
}

int main()
{
    int n;
    cout << "Enter number of books to add to library: ";
    cin >> n;
    Node *start = createLibrary(n);
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Add Book\n2.Remove a book\n3.Show library catalog\n4.Search for a book\n5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addBook(start);
            break;
        case 2:
            removeBook(start);
            break;
        case 3:
            showBooks(start);
            break;
        case 4:
            searchBook(start);
            break;
        case 5:
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