#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;
    Node* prev;
    Node() {
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    ~Node() {
        // Add code for memory deallocation if needed
    }
};

// INSERTION OPERATION ON DOUBLY LINKED LIST
void insertAtHead(Node* &head, Node* &Tail, int data) {
    // check for empty LL
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        Tail = newNode;
        return;
    }
    // Step 1
    Node* newNode = new Node(data);
    // Step 2
    newNode->next = head;
    // Step 3
    head->previous = newNode;
    // Step 4
    head = newNode;
}

// Insert a node at the tail of LL
void insertAtTail(Node* &head, Node* &Tail, int data) {
    // check for empty Ll
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        Tail = newNode;
        return;
    }
    // Step 1: Create a Node
    Node* newNode = new Node(data);
    // Step 2:
    Tail->next = newNode;
    // Step 3:
    newNode->previous = Tail;
    // Step 4:
    Tail = newNode;
}

int findlength(Node* &head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtposition(int data, int position, Node* &head, Node* &Tail) {
    // check for empty Ll
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        Tail = newNode;
        return;
    }
    if (position == 1) {
        insertAtHead(head, Tail, data);
        return;
    }
    int length = findlength(head);
    cout << endl;
    if (position > length) {
        insertAtTail(head, Tail, data);
        return;
    }
    // Step 1: FIND POSITION : PREVIOUS AND CURRENT
    int i = 1;
    Node* previous = head;
    while (i < position - 1) {
        previous = previous->next;
        i++;
    }
    Node* current = previous->next;
    // Step 2: Create a Node
    Node* newNode = new Node(data);
    // Step 3:
    previous->next = newNode;
    // Step 4:
    newNode->prev = previous;
    // Step 5:
    current->prev = newNode;
    // Step :6
    newNode->next = current;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// DELETE OPERATION IN DOUBLY LINKED LIST
void deleteNode(int position, Node* &head, Node* &Tail) {
    if (head == NULL) {
        cout << "LINKED LIST IS EMPTY";
        return;
    }
    int length = findlength(head);
    if (position > length) {
        cout << "PLEASE ENTER A VALID POSITION" << endl;
        return;
    }

    // SINGLE NODE
    if (head->next == NULL) {
        Node* temp = head;
        head = NULL;
        Tail = NULL;
        delete temp;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == length) {
        // delete last node
        Node* temp = Tail;
        Tail = Tail->previous;
        temp->previous = NULL;
        Tail->next = NULL;
        delete temp;
        return;
    }
    // delete from middle
    int i = 1;
    Node* left = head;
    while (i < position - 1) {
        left = left->next;
        i++;
    }
    Node* current = left->next;
    Node* right = current->next;

    left->next = right;
    right->previous = left;
    current->previous = NULL;
    current->next = NULL;
    delete current;
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* head = first;
    Node* Tail = third;

    first->next = second;
    second->previous = first;

    second->next = third;
    third->previous = second;

    cout << "Original List: ";
    print(head);
    cout << endl;
    cout << endl;

    insertAtHead(head, Tail, 101);
    cout << "List after inserting 101 at the head: ";
    print(head);
    cout<<endl;
    cout << endl;
    

    insertAtTail(head, Tail, 501);
    cout << "List after inserting 501 at the tail: ";
    print(head);
    cout<<endl;
    
    
    insertAtposition(401, 1, head, Tail);
    cout << endl<< "List after inserting 401 at position 6: ";
    

    deleteNode(5, head, Tail);
    cout <<endl<<endl<< "List after deleting node at your selected position: ";
    print(head);
    


    return 0;
}
