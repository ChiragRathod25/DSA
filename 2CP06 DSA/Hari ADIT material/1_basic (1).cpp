#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Creation of a queue
    queue<int> q;

    // Insertion
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Printing and removing elements (FIFO order)
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
