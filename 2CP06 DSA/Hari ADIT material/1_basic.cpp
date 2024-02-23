// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){

//     //creation
//     stack<int>s;

//     //insertion
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
    
//     //remove
//     s.pop();
    
//     //check element on top
//     cout<<"Element on top is:"<<s.top()<<endl;

//     //size
//     cout<<"Size of element is:"<<s.size()<<endl;

//     //check empty
//     if(s.empty()){
//         cout<<"The stack is empty";
//     }
//     else{
//     cout<<"The stack is not empty";
//     }
//     return 0;
// }


#include<iostream>
#include<stack>
using namespace std;
int main(){

    //creation
    stack<int>s;

    //insertion
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
    