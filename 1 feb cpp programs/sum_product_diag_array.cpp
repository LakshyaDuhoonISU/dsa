//wap to calculate and display the sum and product of diagonal elements of 2d array
#include<iostream>
using namespace std;
int main()
{
    int n,sum=0,product=1;
    cout<<"Enter number of rows for square matrix: ";
    cin >> n;
    int arr[n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<"Enter "<<i+1<<" row and "<<j+1<<" column element: ";
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<"|";
        for (int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"|";
        }
        cout<<endl;
    }
    for (int i=0;i<n;i++)
    {
        sum+=arr[i][i];
        product*=arr[i][i];
    }
    cout<<"Sum of diagonal elements: "<<sum<<endl<<"Product of diagonal elements: "<<product<<endl;
    return 0;
}