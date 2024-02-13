// linked list containing student marks and calculate total sum and percentage and print it
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
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
        cout << "Enter marks for student " << i + 1 << ": ";
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
        int j = 1;
        int studentMarks = 0;
        cout << "Student " << j << " Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << ptr->marks[i] << " ";
            studentMarks += ptr->marks[i];
        }
        double average = static_cast<double>(studentMarks) / 5;
        cout << "\nSum: " << studentMarks << "\nAverage: " << average << "%" << endl;
        ptr = ptr->next;
        j++;
    }
    delete start;
    return 0;
}