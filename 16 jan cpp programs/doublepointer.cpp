//program to demonstrate double pointer
#include<iostream>
using namespace std;
int main()
{
    int a=5;
    int *ptr;
    ptr=&a;
    int **ptr1; //double pointer is used to point to a pointer
    ptr1=&ptr; //ptr1 stores memory address of ptr, *ptr1 points to value in ptr pointer(memory address of variable a), **ptr1 gives value of variable a
    cout<<a<<endl<<ptr<<endl<<*ptr<<endl<<ptr1<<endl<<*ptr1<<endl<<**ptr1<<endl;
    return 0;
}