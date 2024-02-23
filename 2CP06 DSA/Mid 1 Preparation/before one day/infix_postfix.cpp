#include<iostream>
#include<string>
#include<stack>
using namespace std;
int get_priority(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/') {
        return 2;
    }
    else if(c=='+'||c=='-') 
    {
    return 1;
    }
    return -1;
}
int main(void){
    string infix;
    string postfix;
    cout<<"Enter infix : ";
    cin>>infix;
    stack<char> s;
    for(int i=0;i<infix.size();i++){
        char c=infix[i];
        if(isalnum (c)){
            postfix+=c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if(c==')'){
            while(!s.empty()&&s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop(); //pop (
        }
        else if(c=='^'){
            while(!s.empty()&&get_priority(c)<get_priority(s.top())){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
        else{     
            while ((!s.empty()) &&( get_priority(c)<=get_priority(s.top()))) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }   
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    cout<<"Postfix Expression :"<<postfix<<endl;
    return 0;
}