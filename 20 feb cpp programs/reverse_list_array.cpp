//reversing a list using stack (array)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin >> n;
    int stack[n],list[n],top=-1;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" element: ";
        cin >> list[i];
        top++;
        stack[top]=list[i];
    }
    cout<<"List: ";
    for (int i=0;i<n;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        list[i]=stack[top];
        top--;
    }
    cout<<"Reversed list: ";
    for (int i=0;i<n;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
    return 0;
}