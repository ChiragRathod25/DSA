#include<iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int main(void){
    cout<<endl<<"Stack Demonstration :";
    stack<int> myStack;
    myStack.push(37);
    myStack.push(71);
    myStack.push(41);
    while (!myStack.empty())
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    cout<<endl;

    cout<<"Queue Demonstration :";
    queue<int> myQueue;
    myQueue.push(21);
    myQueue.push(87);
    myQueue.push(65);
    while(!myQueue.empty()){
        cout<<myQueue.front()<<" ";
        myQueue.pop();
    }
    cout<<endl;

    cout<<"Deque Demonstration :";
    deque<int> mydeque;
    mydeque.push_back(21);
    mydeque.push_back(54);
    mydeque.push_front(37);

    for (auto it = mydeque.begin(); it != mydeque.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // stack - LIFO
    // queue - FILO - pushes element into back only 
    // deque - pushes element into both front and back both 
    return 0;
}