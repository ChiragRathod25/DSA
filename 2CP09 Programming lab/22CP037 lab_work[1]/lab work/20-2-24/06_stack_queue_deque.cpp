#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;
    deque<int> d;

    cout << "Stack" << endl;
    s.push(5);
    s.push(4);
    s.push(2);
    s.push(1);
    cout << "Poped : " << s.top() << endl;
    s.pop();
    cout << "Poped : " << s.top() << endl;
    s.pop();

    cout << "Queue" << endl;
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(1);
    cout << "Poped : " << q.front() << endl;
    q.pop();
    cout << "Poped : " << q.front() << endl;
    q.pop();

    cout << "Deque" << endl;
    d.push_front(1);
    d.push_back(2);
    d.push_front(5);
    d.push_back(4);
    d.pop_back();
    d.pop_front();

    cout << "First element : " << d.front() << " Last element :" << d.back() << endl;

    return 0;
}