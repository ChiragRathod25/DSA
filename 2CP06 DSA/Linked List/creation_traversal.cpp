#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
public:
    void set_data(int d,Node*n=nullptr){
        next=n;
        data=d;
    }
    int get_data(){
        return data;
    }
    Node* next_add(){
        return next;
    }
};
void traversal(Node*ptr){
    while(ptr!=NULL){
    cout<<ptr->get_data()<<endl;
    ptr=ptr->next_add();
    }
}
int main(void){
    Node * head=new Node();
    Node * first=new Node();
    Node * second=new Node();

    head->set_data(24,first);
    first->set_data(432,second);
    second->set_data(32);

    traversal(head);
    return 0;
}