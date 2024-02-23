#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
int get_priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}
int main(void)
{
    char infix[100];
    char prefix[100];
    cout << "Enter infix:";
    cin >> infix;
    strrev(infix); // reverse input string
    cout << infix << endl;
    stack<char> s;
    int j = 0, i = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            s.push(ch);
        }
        else if (ch == '(')
        { // here if we get (  we pop all elements till ) because intitally we reversed string  so it will be like )...(
            while (!s.empty() && s.top() != ')')
            {
                prefix[j++] = s.top();
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (ch == '^')
        {   //we simply push it to stack becase its priority is 3
            while (!s.empty() && (get_priority(ch) <= get_priority(s.top())))
            {
                prefix[j++] = s.top();
                s.pop();
            }
            s.push(ch);
        }
        else
        {   //pop all elements till all lower priority is poped, not with same priority
            while (!s.empty() && (get_priority(ch) < get_priority(s.top())))
            {
                prefix[j++] = s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        prefix[j++] = s.top();
        s.pop();
    }
    prefix[j] = '\0';
    strrev(prefix); // reversing final output string because initially we reversed input string
    cout << "Prefix Expression :" << prefix << endl;
    return 0;
}