#include<iostream>
using namespace std;
class Node{
    
    public:
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Linkedlist{
    Node *head;
    public:
    Linkedlist(){
        head=NULL;
    }
    void insertNode(int);
    void printList();
    void deleteNode(int);
};
void Linkedlist::deleteNode(int d){
    Node*temp=head;
    if(temp->next==NULL){
        cout<<"Linked List is Empty "<<endl;
        return;
    }
    Node*temp2=head->next;
    Node*temp0;
    while(temp->next!=NULL){
        if(temp->data==d){
            temp0->next=temp2;
            break;
        }
        if(temp->next==head){
        temp0=temp;
        }
        else{
        temp0=temp;
        temp=temp->next;
        temp2=temp2->next;
        }
    }
}

void Linkedlist::insertNode(int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
} 

void Linkedlist::printList(){
    Node* temp=head;
    if(temp==NULL){
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(void){
    Linkedlist list;
    int choice,temp;
    while(true){
        cout<<"1.Insert"<<endl
            <<"2.Display"<<endl
            <<"3.Delete"<<endl
            <<"4.Exit"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                cin>>temp;
                list.insertNode(temp);
                break;
            case 2:
                list.printList();
                break;
            case 3:
                cin>>temp;
                list.deleteNode(temp);
                break;
            case 4:
                exit(0);
                break;  
            default:
                break;
            }
    }
    return 0;
}