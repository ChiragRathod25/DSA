#include<iostream>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;
    public:
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
    static Node*  append(Node* root,int data){
        Node* newNode = new Node(data);
        if(root==nullptr) return newNode;
        if(data<root->data){
              root->left=append(root->left,data);
        }
        else {
             root->right=append(root->right,data);
        }
        return root;
    }
    void inorder(Node *root){
        if(root==nullptr)  return;
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }

    void preorder(Node *root){
        if(root==nullptr)  return;
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root){
        if(root==nullptr)  return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }

};
int main(){
    Node *root=nullptr;
    root=root->append(root,21);
    root=root->append(root,26);
    root=root->append(root,43);
    root=root->append(root,2);
    root=root->append(root,98);
    root->inorder(root);
    cout<<endl;
    root->preorder(root);
    cout<<endl;
    root->postorder(root);

    return 0;
}