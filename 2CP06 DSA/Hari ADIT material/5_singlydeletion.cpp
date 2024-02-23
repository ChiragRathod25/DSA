#include<iostream>
using namespace std;

class Node {
public:
    int data;        // Declare an integer data field for the node.
    Node* next;      // Declare a pointer to the next node in the linked list.

    Node() {
        this->data = 0;  // Default constructor: Initialize data to 0.
        this->next = NULL;  // Initialize next pointer to NULL.
    }

    Node(int data) {
        this->data = data;  // Constructor with data parameter: Initialize data to the provided value.
        this->next = NULL;  // Initialize next pointer to NULL.
    }
    ~Node(){
        cout<<endl<<"Node with value:"<<" "<<this->data<<" delete";  // Destructor to print a message when a node is deleted.
    }
};

// Insert a node right at the head of the linked list
void insertAtHead(Node* &head, Node* &Tail, int data) {
    // Check for an empty linked list
    if(head==NULL){
        Node* newNode= new Node(data);  // Create a new node with the provided data.
        head=newNode;  // Set both head and Tail to the new node.
        Tail=newNode;
        return;
    }
    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Connect the new node to the current head
    newNode->next = head;
    // Step 3: Update the head to the new node
    head = newNode;
}

// Insert a node at the tail of the linked list
void insertAtTail(Node* &head, Node* &Tail, int data) {
    // Check for an empty linked list
     if(head==NULL){
        Node* newNode= new Node(data);  // Create a new node with the provided data.
        head=newNode;  // Set both head and Tail to the new node.
        Tail=newNode;
        return;
    }
    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Connect the current tail to the new node
    Tail->next=newNode;
    // Step 3: Update the tail to the new node
    Tail = newNode;
}

// Function to find the length of the linked list
int findlength(Node* &head){
    int length=0;
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";  // Print the data of each node as you traverse the list.
        temp=temp->next;
        length++;  // Increment the length for each node.
    }
    return length;
}

// Function to insert a node at a specific position in the linked list
void insertAtposition(int data , int position , Node* &head , Node* &Tail) {
    // Check for an empty linked list
     if(head==NULL){
        Node* newNode= new Node(data);  // Create a new node with the provided data.
        head=newNode;  // Set both head and Tail to the new node.
        Tail=newNode;
        return;
    }
    if(position==0){
        insertAtHead(head,Tail,data);  // If the position is 0, insert at the head.
        return;
    }
    int length=findlength(head);
    cout<<endl;
    if(position >=length){
        insertAtTail(head,Tail,data);  // If the position is greater than or equal to the length, insert at the tail.
        return;
    }
    // Step 1: Find the position: previous and current
    int i=1;
    Node* previous = head;
    while(i<position){
        previous=previous->next;
        i++;
    }
    Node* current =previous->next;
    // Step 2: Create a new node
    Node* newNode = new Node(data);
    // Step 3: Connect the new node to the current node
    newNode ->next=current;
    // Step 4: Connect the previous node to the new node
    previous->next = newNode;
}

// Function to print the linked list
void print(Node* head , Node* Tail) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";  // Print the data of each node as you traverse the list.
        temp = temp->next;
    }
}

// Function to delete a node at a specific position in the linked list
void deleteNode(int position,Node* &head,Node* &tail){
    if(head==NULL){
        cout<<"cannot delete, LL is empty.";  // Print a message if the linked list is empty.
        return;
    }
    // Delete the first node
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next =NULL;
        delete temp;
        return;
    }
    // Delete the last node
    int length=findlength(head);
    // Step 1: Find the previous node
    if(position==length){
        int i=1;
        Node* previous=head;
        while(i<position-1){
            previous=previous->next;
            i++;
        }
        // Step 2: Disconnect the last node from the previous node
        previous->next=NULL;
        // Step 3: Update the tail to the previous node
        Node* temp=tail;
        // Step 4: Update the tail
        tail=previous;
        // Step 5: Delete the last node
        delete temp;
        return;
    }

    //Delete the middle Node
    //Step:1 Find previous and current
    int i=1;
    Node* previous = head;
    while(i<position-1){
        previous=previous->next;
        i++;
    }
    Node* current= previous->next;
    //Step 2:
    previous->next=current->next;
    //Step 3:
    current->next=NULL;
    //Step 4:
    delete current;
}

int main() {
    Node* head = NULL;
    Node* Tail = NULL;

    insertAtHead(head, Tail, 20);  // Insert 20 at the head.
    insertAtHead(head, Tail, 30);  // Insert 30 at the head.

    insertAtTail(head, Tail, 77);  // Insert 77 at the tail.
    insertAtTail(head, Tail, 76);  // Insert 76 at the tail.

    print(head,Tail);  // Print the linked list.
    cout<<endl;

    deleteNode(4,head,Tail);  // Delete the first node.
    cout<<endl;
    print(head,Tail);  // Print the modified linked list.
    cout<<endl;
    }
