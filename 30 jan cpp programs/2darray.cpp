//create a matrix and print it
#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cout<<"Enter number of rows: ";
    cin >> row;
    cout<<"Enter number of columns: ";
    cin >> col;
    int arr[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout<<"Enter "<<i+1<<" row and "<<j+1<<" column element: ";
            cin>>arr[i][j];
        }
    }
    cout<<"Matrix-"<<endl;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}