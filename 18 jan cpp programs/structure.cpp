//program to demonstrate structure
#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int roll_no;
    string name,dob;
};
int main()
{
    int n,a;
    cout<<"Enter number of students: ";
    cin>>n;
    Student student[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter roll no: ";
        cin>>student[i].roll_no;
        cout<<"Enter name: "<<endl;
        cin>>student[i].name;
        cout<<"Enter dob(DD/MM/YYYY): "<<endl;
        cin>>student[i].dob;
    }
    cout<<"Student Details: "<<endl<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<"Roll No: "<<student[i].roll_no<<endl;
        cout<<"Name: "<<student[i].name<<endl;
        cout<<"DOB: "<<student[i].dob<<endl<<endl;
    }
    cout<<"Enter Roll No to search for student: ";
    cin>>a;
    for (int i=0;i<n;i++)
    {
        if (student[i].roll_no==a)
        {
            cout<<"Student found!"<<endl<<"Name: "<<student[i].name<<endl<<"Roll No: "<<student[i].roll_no<<endl<<"DOB: "<<student[i].dob<<endl;
            break;
        }
    }
    return 0;
}