#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node(){
        this->data=0;
        this->next=NULL;
    }
    // Constructor with data parameter
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack(){
        top=NULL;
    }

    // Function to push data onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << data << " ";
    }

    // Function to pop data from the stack
    void pop() {
        if (top==NULL) {
            cout << "Stack underflow, can't delete element." << endl;
        } else {
            cout << "Popped: " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to get the top element of the stack
    int getTop() {
        if (top==NULL) {
            cout << "There is no element in the stack." << endl;
            return -1; // Return an error value
        } else {
            return top->data;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;

    s.push(20);
    s.push(50);
    s.push(60);
    s.push(77);
    s.push(90);

    cout << "Stack elements:" << endl;
    while (!s.isEmpty()) {
        cout << "Top: " << s.getTop() << endl;
        s.pop();
    }

    return 0;
}
