#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        next = nullptr;
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
    }
    void insert_index(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *temp1 = this;
        Node *temp2 = this->next;
        int i = 0;
        while (temp1 != nullptr)
        {
            if (i == index-1 )
            {
                break;
            }
            i++;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = newNode;
        newNode->next = temp2;
    }
    Node *insert_front(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this;
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
                // cout<<temp->data<<endl;
                temp1->next = nullptr;
                delete temp;
                break;
            }
            temp1 = temp1->next;
        }
    }
    Node *delete_first()
    {
        Node *temp = this;
        Node *temp2 = temp->next;
        delete this;
        return temp2;
    }
    void delete_index(int index)
    {
        Node *temp = this;
        Node *temp1 = this->next->next;
        int i = 0;
        while (temp->next != nullptr)
        {
            if (i == index - 1)
            {
                temp->next->data = '\0';
                delete temp->next;
                temp->next = temp1;
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
int main(void)
{
    Node *head = new Node(12);
    head->append(5);
    head->append(56);
    head->append(155);
    head->display();
    head->insert_index(37, 2);
    head->display();
    head->insert_index(12, 1);
    head->display();
    head = head->insert_front(23);
    head->display();
    head->delete_last();
    head->display();
    head = head->delete_first();
    head->display();
    head->delete_index(3);
    head->display();

    return 0;
}