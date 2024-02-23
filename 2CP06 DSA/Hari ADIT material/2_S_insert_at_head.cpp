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
void insertAtHead(Node* &head,int data) {
    // Step 1
    Node* newNode = new Node(data);
    // Step 2
    newNode->next = head;
    // Step 3
    head = newNode;
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
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    insertAtHead(head,  77);
    insertAtHead(head,  76);
    
    print(head);
}
