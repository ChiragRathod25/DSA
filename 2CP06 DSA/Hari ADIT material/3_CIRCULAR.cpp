#include<iostream>
using namespace std;

class Queue {
public:
    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data) {
        if (front == 0 && rear == size - 1) {
            cout << "Queue is Full";
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        if (front == -1) {
            cout << "Queue is Empty";
        } else if (front == rear) {
            arr[front] = -1;
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }
};
int main() {
    // Example usage of the Queue class
    Queue myQueue(5); // Create a queue of size 5

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    // Print the contents of the queue
    cout << "Queue elements after pushing: ";
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        cout << myQueue.arr[i] << " ";
    }
    cout << endl;

    // Attempting to push more elements to show "Queue is Full" message
    myQueue.push(6);
    
    cout<<endl;
    // Pop some elements to demonstrate pop operation
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();

    // Attempting to pop more elements to show "Queue is Empty" message
    myQueue.pop();

    return 0;
}
