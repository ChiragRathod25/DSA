#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *head;
    node *last;
    node() {}
    node(int x) : data(x)
    {
        next = NULL;
    }
};
class stack
{
public:
    node *top;
    stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        node *temp = new node(x);
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        node *temp = top;
        if (temp != NULL)
        {
            // cout << top->data << endl;
            top = top->next;
        }
        else{
            cout<<"overflow!";
        }
    }
    void display()
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    stack s;
    s.push(29);
    s.push(37);
    s.push(44);
    s.display();
    s.pop();
    s.display();
    s.push(3);
    s.display();
}
