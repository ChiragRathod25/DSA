#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOpeningbracket(char c){
    return c=='('||c=='{'||c=='[';
}
bool isClosingbracket(char c){
    return c==')'||c=='}'||c==']';
}
int main(void){
    string expression;
    cout<<"Enter expression : ";
    cin>>expression;
    stack<char> s;
    bool flag=true;
    for(char c:expression){
        if(isOpeningbracket(c)){
            s.push(c);
        }
        else if(isClosingbracket(c)){
            char temp;
            if(s.top()=='('){
                temp=')';
            }
            else if(s.top()=='{'){
                temp='}';
            }
            else if(s.top()=='['){
                temp=']';
            }
            if(c==temp){
                flag=true;
                s.pop();
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
    }
    if(flag){
        cout<<"Correct Expression";
    }
    else{
        cout<<"Incorrect Expression";
    }
  return 0;
}