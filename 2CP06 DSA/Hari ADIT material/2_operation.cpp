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
        front = 0;
        rear = 0;
    }

    void push(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    void pop() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
        } else {
            arr[front] = -1;
            front++;
            if (front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    int getSize() {
        return rear - front;
    }

    int getFront() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Queue q(10);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    cout << "SIZE OF QUEUE: " << q.getSize() << endl;
    cout << "FRONT OF QUEUE: " << q.getFront() << endl;

    if(q.isEmpty()){
        cout<<"Q EMPTY";
    }
        else{
            cout<<"Q not Empty";
        }
    return 0;
}
