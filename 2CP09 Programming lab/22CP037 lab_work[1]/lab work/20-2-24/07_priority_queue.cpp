#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(5);
    q.push(50);
    q.push(6);
    q.push(2);
    q.push(6);

    cout << "First element is : " << q.top() << endl;
    q.pop();
    cout << "First element is : " << q.top() << endl;

    return 0;
}