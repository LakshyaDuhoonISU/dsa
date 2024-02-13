//wap to find largest and second largest element from n numbers using an array
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    int max=-2147483647,second=-2147483647;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
        if (arr[i]>max)
        {
            second=max;
            max=arr[i];
        }
        else if (arr[i]>second)
        {
            second=arr[i];
        }
    }
    cout<<"Largest element: "<<max<<endl<<"Second largest element: "<<second<<endl;
    return 0;
}