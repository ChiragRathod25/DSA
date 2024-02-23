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

    void pushRear(int data) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
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

    void pushFront(int data) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue is Full";
        } else if (front == -1) {
            front = rear = 0;
            arr[front] = data;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
            arr[front] = data;
        } else {
            front--;
            arr[front] = data;
        }
    }

    void popRear() {
        if (front == -1) {
            cout << "Queue is Empty";
        } else if (front == rear) {
            arr[front] = -1;
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    void popFront() {
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

    myQueue.pushRear(1);
    myQueue.pushRear(2);
    myQueue.pushRear(3);
    myQueue.pushRear(4);
    myQueue.pushRear(5);

    // Print the contents of the queue
    cout << "Queue elements after pushing to rear: ";
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        cout << myQueue.arr[i] << " ";
    }
    cout << endl;

    myQueue.pushFront(6);

    // Print the contents of the queue
    cout << "Queue elements after pushing to front: ";
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        cout << myQueue.arr[i] << " ";
    }
    cout << endl;

    // Pop some elements from rear
    myQueue.popRear();
    myQueue.popRear();
    myQueue.popRear();

    // Print the contents of the queue
    cout << "Queue elements after popping from rear: ";
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        cout << myQueue.arr[i] << " ";
    }
    cout << endl;

    // Pop some elements from front
    myQueue.popFront();
    myQueue.popFront();

    // Print the contents of the queue after popping from front
cout << "Queue elements after popping from front: ";
if (myQueue.front == -1) {
    cout << "Queue is Empty";
} else {
    for (int i = myQueue.front; i != (myQueue.rear + 1) % myQueue.size; i = (i + 1) % myQueue.size) {
        cout << myQueue.arr[i] << " ";
    }
}
cout << endl;
}
