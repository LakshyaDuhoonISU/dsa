// linked list containing student name,rollno, and marks and calculate total sum and percentage and print student info
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node
{
public:
    string name;
    string rollno;
    int marks[5];
    Node *next;
    Node()
    {
        fill_n(marks, 5, -1);
        next = NULL;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node();
        cout << "Enter student " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, newNode->name);
        cout << "Enter roll number: ";
        cin >> newNode->rollno;
        cout << "Enter marks: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> newNode->marks[j];
        }
        if (start == NULL)
        {
            start = newNode;
            ptr = start;
        }
        else
        {
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    ptr = start;
    while (ptr != NULL)
    {
        int studentMarks = 0;
        cout << "\nStudent Name: " << ptr->name << "\nRoll No: " << ptr->rollno << "\nMarks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << ptr->marks[i] << " ";
            studentMarks += ptr->marks[i];
        }
        double average = static_cast<double>(studentMarks) / 5;
        cout << "\nSum: " << studentMarks << "\nAverage: " << average << "%" << endl;
        ptr = ptr->next;
    }
    delete start;
    return 0;
}