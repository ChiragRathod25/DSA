#include<iostream>
#include<queue>
using namespace std;
class Node{
    int data;
    Node *left;
    Node *right;
    public:
    Node(int data):data(data){
        this->left=nullptr;
        this->right=nullptr;
    }
    static Node * insert(Node *root,int data){
        Node *newNode=new Node(data);
        if(root==nullptr) {
            root=newNode;
            return root;
        }
        
        queue<Node*> q; 
        q.push(root);
        while(1){
            Node *tp=q.front();
            if(tp->left==nullptr) {
                tp->left=newNode;
                break;
            }
            else{
                q.push(tp->left);
            }
            if(tp->right==nullptr){
                tp->right=newNode;
                break;
            }
            else{
                q.push(tp->right);
            }
        }
        return root;
    }
    void inorder(Node *root){
        if(root==nullptr)  return;
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }

};
int  main(){

    Node *root=nullptr;
    root=root->insert(root,50); 
    root=root->insert(root,99); 
    root=root->insert(root,10); 
    root->inorder(root);

    return 0; 
}