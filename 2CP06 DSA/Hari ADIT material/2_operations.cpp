// #include<iostream>
// using namespace std;
// class Stack{
//     public:

//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//     arr = new int{size};
//     top=-1;
//     }

//     void push(int data){
//     if(size-top>1){
//         //space availble
//         //insert
//         top++;
//         arr[top]=data;
//         }
//         else
//         cout<<"Space not Available."<<endl;
//         }

//     void pop(){
//     if(top==-1){
//         //stack is empty
//         cout<<"Stack underflow,cant delete element.";
//     }
//     else{
//         //stack is not empty
//         top--;
//     }
//     }

//     int getTop(){
//         if(top==-1){
//             cout<<"There is no element in stack."<<endl;
//         }
//         else 
//         return arr[top];
//     }
//     int getSize(){
//         return top+1;
//     }

//     bool isEmpty(){
//         if(top==-1){
//             return true;
//         }
//         else 
//             return false;

//     }
// };

// int main(){
//     Stack s(10);
//     //insertion
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
    
//     while(!s.isEmpty()){
//         cout<<s.getTop()<<" ";
//         s.pop();
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

const int SIZE = 100; // Maximum stack size

int arr[SIZE]; // Array to store the stack elements
int top = -1;   // Initialize top of the stack to -1

// Function to push data onto the stack
void push(int data) {
    if (SIZE - top > 1) {
        // Space available in the stack
        // Insert the data
        top++;
        arr[top] = data;
        cout << data << " ";
    } else {
        // Stack is full
        cout << "Space not Available." << endl;
    }
}

// Function to pop data from the stack
void pop() {
    if (top == -1) {
        // Stack is empty
        cout << "Stack underflow, can't delete element." << endl;
    } else {
        cout << "Popped: " << arr[top] << endl;
        // Pop the top element from the stack
        top--;
    }
}

// Function to get the top element of the stack
int getTop() {
    if (top == -1) {
        // Stack is empty
        cout << "There is no element in stack." << endl;
        return -1; // Return an error value
    } else {
        // Return the top element of the stack
        return arr[top];
    }
}

// Function to get the size of the stack
int getSize() {
    return top + 1;
}

// Function to check if the stack is empty
bool isEmpty() {
    if (top == -1) {
        // Stack is empty
        return true;
    } else {
        // Stack is not empty
        return false;
    }
}

int main() {
    int maxSize;

    cout << "Enter the size of the stack: ";
    cin >> maxSize;

    if (maxSize > SIZE) {
        // Input size exceeds maximum stack size
        cout << "Stack size is more." << endl;
        return 1;
    }

    // Insertion into the stack
    cout << "Enter elements:";
    for (int i = 0; i < maxSize; i++) {
        int data;
        cin >> data;
        push(data);
    }
    // Displaying top element and popping from the stack
    cout << endl<<"Stack elements (Top to Bottom):" << endl;
    while (!isEmpty()) {
        cout << "Top: " << getTop() << endl;
        pop();
    }

    return 0;
}
