//creation of linked list using struct
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *start;
    struct node *n1;
    n1 = (struct node *)malloc(sizeof(struct node));
    start = n1;
    n1->data = 33;
    n1->next = NULL;
    struct node *n2;
    n2 = new node();
    n1->next = n2;
    n2->data = 48;
    n2->next = NULL;
    struct node *n3;
    n3 = new node();
    n2->next = n3;
    n3->data = 51;
    n3->next = NULL;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = ptr->next;
    }
    for (ptr = start; ptr != NULL; ptr=ptr->next)
    {
        cout << ptr->data << endl;
    }
    free(start);
    return 0;
}