//create an array of pointers and add sum of each subjects and display average of each subject
#include<iostream>
using namespace std;

void avgSubject(int *ptrarray[5])
{
    int sum[5],avg[5];
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            sum[i]+=(*ptrarray[i]+j);
        }
        avg[i]=sum[i]/5;
    }
    for (int i=0;i<5;i++)
    {
        cout<<"Average of subject "<<i+1<<" is "<<avg[i]<<endl;
    }
}

int main()
{
    int sub1[5],sub2[5],sub3[5],sub4[5],sub5[5];
    for (int i=0;i<5;i++)
    {
        cout<<"Enter subject "<<i+1<<" : "<<endl;
        cin>>sub1[i];
        cin>>sub2[i];
        cin>>sub3[i];
        cin>>sub4[i];
        cin>>sub5[i];
    }
    int *ptrarray[5]={sub1,sub2,sub3,sub4,sub5};
    avgSubject(ptrarray);
    return 0;
}