#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
// Insert a node at the head of linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    // Check for empty LL
    if(head==NULL){
    Node* newNode = new Node(data);
    head=newNode;
    tail=newNode;
    return;
    }
    // Step 1
    Node* newNode = new Node(data);
    //Step 2
    newNode->next = head;
    // Step 3
    head = newNode;
}
//Insert a node at the tail of Linked List
void insertAtTail(Node* &head, Node* &tail, int data) {
    // Check for Empty LL
if (head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
} else {
    // If the linked list is not empty, proceed with adding a new node to the end
    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Link the new node to the current tail
    tail->next = newNode;

    // Step 3: Update the tail to the new node
    tail = newNode;
}


}
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail, 20);
    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 77);
    insertAtHead(head,tail, 76);
    insertAtTail(head,tail, 25);
    
    print(head);
}
