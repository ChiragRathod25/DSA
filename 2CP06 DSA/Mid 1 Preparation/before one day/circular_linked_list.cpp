//This is not a correct circular Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        previous=nullptr;
    }
    void append(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = this;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous=temp;
    }
    void insert_index(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *temp1 = this;
        Node *temp2 = this->next;
        int i = 0;
        while (temp1 != nullptr)
        {
            if (i == index - 1)
            {
                break;
            }
            i++;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //linking
        temp1->next = newNode;
        newNode->next = temp2;
        newNode->previous=temp1;
        temp2->previous=newNode;
    }
    Node *insert_front(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this;
        this->previous=newNode;
        return newNode;
    }
    void delete_last()
    {
        Node *temp = this;
        Node *temp1 = this;
        while (temp != nullptr)
        {   
            temp = temp->next;
            if (temp->next == nullptr)
            {
                delete temp;
                temp1->next=nullptr;
                break;
            }
            temp1 = temp1->next;
        }
    }
    Node *delete_first()
    {
        Node *temp = this;
        Node *temp2 = temp->next;
        temp2->previous=nullptr;
        delete this;
        return temp2;
    }

    void delete_index(int index)
    {
        Node *temp = this;
        Node *temp1 = this->next->next;
        int i = 0;
        while (temp!= nullptr)
        {
            if (i == index - 1)
            {
                delete temp->next;
                temp->next = temp1;
                temp1->previous=temp;
                break;
            }
            temp = temp->next;
            temp1 = temp1->next;
            i++;
        }
    }
    void display()
    {
        Node *temp = this;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void insertAthead(Node* &head,int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        newNode->next=newNode;
    }
    newNode->next=head;
    head=newNode;
}
void insertAttail(Node* &head,int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
}
void display(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(void)
{
    Node *head=NULL;

cout<<"This is not a correct circular Linked List";
    insertAthead(head,43);
    insertAthead(head,23);
    display(head);
    insertAttail(head,12);
    display(head);
    return 0;
}
