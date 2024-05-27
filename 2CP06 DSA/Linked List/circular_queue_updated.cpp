//circular code 
#include <iostream>

#define MAX_SIZE 5

using namespace std;

class CircularQueue {
private:
    char queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(char item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = item;
        cout << "Push : Value : " <<" : "<<queue[rear] << "front : " << front << "  "<< "rear : " << rear << endl;
    }

    void dequeue() {
     
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
           cout<<"POP  Method Executed"<<endl;
        cout << "front : " << front << "  "<< "rear : " << rear << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        cout << "Queue: ";
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }

    int getFront() { 
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[rear];
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue('P');
    cq.enqueue('Q');
    cq.dequeue();
    cq.dequeue();
    cq.enqueue('R');
    cq.enqueue('S');
    cq.enqueue('T');
    cq.enqueue('U');
    cq.display();

    return 0;
}
