#include<iostream>
#include<queue>
using namespace std;
int main(void){
    // A priority queue is a type of queue that arranges elements based on their priority values. Elements with higher priority values are typically retrieved before elements with lower priority values

    //  if you add an element with a high priority value to a priority queue, it may be inserted near the front of the queue, while an element with a low priority value may be inserted near the back.

    priority_queue<int> pq;
    pq.push(21);
    pq.push(98);
    pq.push(7);
    pq.push(460);
    pq.push(65);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}