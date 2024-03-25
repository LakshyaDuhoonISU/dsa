// parentheses checking using stack(array)
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string parentheses;
    bool is_valid = true;
    char stack[100];
    int top = -1;
    cout << "Enter expression: ";
    getline(cin, parentheses);
    for (int i = 0; i < parentheses.length(); i++)
    {
        if (parentheses[i] == '[' || parentheses[i] == '{' || parentheses[i] == '(')
        {
            top++;
            stack[top] = parentheses[i];
        }
        else if (parentheses[i] == '}')
        {
            if (stack[top] == '{')
            {
                top--;
            }
            else
            {
                is_valid = false;
            }
        }
        else if (parentheses[i] == ']')
        {
            if (stack[top] == '[')
            {
                top--;
            }
            else
            {
                is_valid = false;
            }
        }
        else if (parentheses[i] == ')')
        {
            if (stack[top] == '(')
            {
                top--;
            }
            else
            {
                is_valid = false;
            }
        }
    }
    if (top != -1 || is_valid == false)
    {
        cout << "Parentheses is not valid\n";
    }
    else if (top == -1)
    {
        cout << "Parentheses is not valid\n";
    }
    else
    {
        cout << "Parentheses is valid\n";
    }
    return 0;
}