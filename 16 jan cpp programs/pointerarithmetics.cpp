//program to demonstrate pointer arithmetics
#include<iostream>
using namespace std;
int main()
{
    int a=5,b=3,sum;
    int *ptr1=&a,*ptr2=&b;
    sum=(*ptr1)+(*ptr2);
    cout<<"Sum of "<<*ptr1<<" and "<<*ptr2<<" is "<<sum<<endl;
    (*ptr1)++;
    (*ptr2)--;
    sum=(*ptr1)+(*ptr2);
    cout<<"Sum of "<<*ptr1<<" and "<<*ptr2<<" is "<<sum<<endl;
    return 0;
}