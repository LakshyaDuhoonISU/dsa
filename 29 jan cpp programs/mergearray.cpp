// merge two sorted arrays
#include <iostream>
using namespace std;

void mergeSortedArray(int arr[], int arr1[], int a, int b)
{
    int total[a+b];
    int i = 0, j = 0, k = 0;
    while (i < a && j < b)
    {
        if (arr[i] <= arr1[j])
        {
            total[k] = arr[i];
            i++;
        }
        else
        {
            total[k] = arr1[j];
            j++;
        }
        k++;
    }
    while (i < a)
    {
        total[k] = arr[i];
        i++;
        k++;
    }
    while (j < b)
    {
        total[k] = arr1[j];
        j++;
        k++;
    }
    for (int i = 0; i < (a+b); i++)
    {
        cout << total[i] << endl;
    }
}

int main()
{
    int girls[5], boys[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i + 1 << " girls' marks: ";
        cin >> girls[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i + 1 << " boys' marks: ";
        cin >> boys[i];
    }
    int boys_size=sizeof(boys)/sizeof(int);
    int girls_size=sizeof(girls)/sizeof(int);
    mergeSortedArray(girls, boys, girls_size, boys_size);
    return 0;
}