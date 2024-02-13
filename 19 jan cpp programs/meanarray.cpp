//wap to read and display n numbers using array and print mean of values
#include<iostream>
using namespace std;
int main()
{
    int n,i=0,sum=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    while (i<n)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
        sum+=arr[i];
        i++;
    }
    int j=0;
    cout<<"Elements of array: ";
    while(j<n)
    {
        cout<<arr[j];
        j++;
    }
    cout<<endl<<"Mean: "<<sum/n<<endl;
    return 0;
}