#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *previous;

public:
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
int main(void)
{
    Node *head = new Node(12);
    head->append(5);
    head->append(56);
    head->append(155);
    head->display();
    head->insert_index(37, 2);
    // head->display();
    head->insert_index(12, 1);
    // head->display();
    head = head->insert_front(23);
    head->display();
    head->delete_last();
    // head->display();
    head = head->delete_first();
    // head->display();
    head->delete_index(3);
    head->display();

    return 0;
}
