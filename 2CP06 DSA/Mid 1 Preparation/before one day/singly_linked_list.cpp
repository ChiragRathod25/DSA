#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node(int data=0)
    {
        this->data = data;
        this->next = nullptr;
    }
    void insert(int data){
        Node *newNode=new Node(data);
        Node*temp=this;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    Node* insert_first(int data){
        Node *newNode=new Node(data);
        newNode->next=this;
        return newNode;
    }
    void insert_index(int index,int data){
        int i=0;
        Node*temp=this;
        Node*temp1=this->next;
        Node*newNode=new Node(data);
        while(temp->next!=NULL){
            if(i==index-1) break;
            i++;
            temp=temp->next;
            temp1=temp->next;
        }
            temp->next=newNode;
            newNode->next=temp1;
    }
    void delete_last(){
        Node*temp=this;
        Node*temp1;
        while (temp->next!=NULL)
        {   
            temp1=temp;
            temp=temp->next;
        }
        delete temp;
        temp1->next=nullptr;
    }
    Node* delete_first(){
        Node*temp=this;
        Node*temp1=this->next;
        delete temp;
        return temp1;
    }
    void delete_index(int index){
        Node*temp=this;
        Node*temp1=this->next->next;
        int i=0;
        while(temp->next!=NULL){            
            if(i==index-1) break;
            i++;
            temp=temp->next;
            temp1=temp1->next;
        }
        delete temp->next;
        temp->next=temp1;
    }
    void traverse(){
        Node *temp=this;
        while(temp->next!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Node *head=new Node(10);
    head->insert(4);
    head->insert(3);
    head->traverse();

    head=head->insert_first(42);
    // head=head->insert_first(423);
    head->traverse();

    head->insert_index(3,13); //it will insert at end if we enter over size
    head->traverse();

    head->delete_last();
    head->traverse();

    head=head->delete_first();
    head->traverse();

    head->insert(23);
    head->insert(76);
    head->insert(97);
    head->traverse();
    
    head->delete_index(2);
    head->traverse();
    return 0;
}