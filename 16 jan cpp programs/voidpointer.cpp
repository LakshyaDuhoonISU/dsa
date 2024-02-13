// program to demonstrate use of void or generic pointer

// #include<iostream>
// using namespace std;
// int main()
// {
//     void *ptr; //void pointer(or generic pointer) is used to point to variable of any data type but cannot be used to point to another variable of another data type
//     int a=5;
//     ptr=&a;
//     cout<<ptr<<endl<<*(int *)ptr<<endl; //in order to dereference pointer, we need to type cast it to data type of variable that is pointed to
//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    void *ptr; //cannot use char *ptr as ptr will print character with end of string character, so void pointer is used
    char a='a';
    ptr=&a;
    cout<<a<<endl<<ptr<<endl<<*(char*)ptr<<endl; //need to use void pointer and type cast to char while printing it to print address
    return 0;
}