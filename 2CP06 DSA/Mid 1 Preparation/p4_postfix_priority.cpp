#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;

int priority(char sign)
{
    if (sign == '+' || sign == '-')
    {
        return 1;
    }
    else if (sign == '*' || sign == '/')
    {
        return 2;
    }
    else if (sign == '^')
    {
        return 3;
    }
    return 0;
}
bool isOpeningbracket(char sign)
{
    return sign == '(' || sign == '{' || sign == '[';
}
bool isClosingbracket(char sign)
{
    return sign == ')' || sign == '}' || sign == ']';
}
int main(void)
{
    while (true)
    {
        string infix;
        cout << "Enter String : ";
        getline(cin, infix);
        string postfix = "";

        stack<char> s;
        char ch;
        for (int i = 0; i < infix.size(); i++)
        {
            ch = infix[i];
            if (isalnum(ch))
            {
                postfix += ch;
            }
            else if (isOpeningbracket(ch))
            {
                s.push(ch);
            }
            else if (isClosingbracket(ch))
            {
                while (!s.empty() && !isOpeningbracket(s.top()))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {   
                while (!s.empty() && (priority(s.top()) > priority(ch) || ((priority(s.top()) == priority(ch) && ch != '^'))))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        
        while (!s.empty())
        {
            postfix += s.top();
            s.pop();
        }
        cout << "Postfix Expression : " << postfix << endl;
    }
    return 0;
}
