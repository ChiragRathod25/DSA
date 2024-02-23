#include <iostream>
#include <stack>
using namespace std;
bool isOpeningbracket(char sign)
{
    return sign == '(' || sign == '{' || sign == '[';
}
bool isClosingbracket(char sign)
{
    return sign == ')' || sign == '}' || sign == ']';
}
int main()
{
    string infix;
    cout << "Enter Expression : ";
    // cin>>infix;
    getline(cin,infix);
    bool isValid;
    stack<char> s;
    for (int i = 0;i< infix.size(); i++)
    {

            // cout<<infix[i]<<endl;
        if (isOpeningbracket(infix[i]))
        {   
            // cout<<infix[i]<<endl;
            s.push(infix[i]);
        }
        else if (isClosingbracket(infix[i]))
        {
            if(s.empty()){
                isValid=false;
                break;
            }
            char temp=s.top();
            char ch;
            if(temp=='('){
                ch=')';
            }
            else if(temp=='{'){
                ch='}';
            }
            else{
                ch=']';
            }
            if (infix[i]==ch)
            {
                // cout<<"Here"<<infix[i]<<endl;
                s.pop();
                isValid = true;
            }
            else
            {
                isValid = false;
                break;
            }
        }
    }
    if (isValid)
    {
        cout << "Valid Expression" << endl;
    }
    else
    {
        cout << "Expression is not correct " << endl;
    }
    return 0;
}
