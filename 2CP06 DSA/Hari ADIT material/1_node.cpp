#include<iostream>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Default constructor initializes data to 0 and next to NULL
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized constructor initializes data with given value and next to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list starting from the given head
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    // Creating nodes for the linked list
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    // Linking nodes to form a linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    // Printing the linked list
    cout << "Linked List: ";
    print(first);

    return 0;
}
/*
  +-----+     +-----+     +-----+     +-----+     +-----+
  |  10 | --> |  20 | --> |  30 | --> |  40 | --> |  50 |
  +-----+     +-----+     +-----+     +-----+     +-----+
Each box represents a Node in the linked list.
The number inside each box represents the data of the node.
The arrow (-->) indicates the next pointer, showing the direction to the next node in the sequence.
The last node has a NULL next pointer, indicating the end of the linked list.
In your code, first, second, third, fourth, and fifth are pointers to the nodes, and they are linked together to form a linked list with the values 10, 20, 30, 40, and 50. The print function is then used to traverse and print the elements of the linked list.
*/