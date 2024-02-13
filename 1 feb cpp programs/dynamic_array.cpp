//creation of dynamic array using calloc function
#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int *arr=(int *)calloc(size,sizeof(int));
    for (int i=0;i<size;i++)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
