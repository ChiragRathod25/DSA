#include <iostream>
using namespace std;
class queue
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    queue(int size)
    {   
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        // cout<<this->size<<endl;
    }
    void push(int n)
    {
        if (rear == size - 1 && front == 0)
        {   
            cout<<"we can't insert "<<n
             << " queue is full !!" << endl;
        }
        else if (front == -1 && rear == -1)
        {   

            front++;
            arr[++rear] = n;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = -1;
            arr[++rear] = n;
        }
        else if (rear == front - 1)
        {
             cout<<"we can't insert "<<n
             << " queue is full !!" << endl;
        }
        else
        {   
            arr[++rear] = n;
        }
        // cout << "Push : Value : " <<n<<" : "<<arr[rear] << "front : " << front << "  "<< "rear : " << rear << endl;
    }
    void pop()
    {   
        if (front == -1)
        {
            cout << "queue is Empty " << endl;
        }
        else if(front==size-1&&rear!=0)
        {
            front=0;
        }
        else {
            front++;
        }
        // cout<<"POP  Method Executed"<<endl;
        // cout << "front : " << front << "  "<< "rear : " << rear << endl;
    }

    void display()
    {
        // cout << "Display Function : " << endl;
        // cout<<"front : "<<front<<" rear :"<<rear<<endl;
        bool isSecond=false;
        int limit=front<rear?rear:front+size;
       for (int i = front; i <=limit; i++)
        {   
            cout << arr[i] << "     ";
             if(i==size-1&&front>rear&&isSecond==false){
                i=-1;
                isSecond=true;
            }
            else if(i==rear && isSecond==true){
                break;
            }
            // cout << "Value : " << arr[i] << "front : " << front << "    "<< "rear : " << rear << endl;
        }
        cout<<endl;        
    }
};
int main()
{
    int n;
    // cout << "Enter the size of the queue: ";
    // cin >> n;
    queue q(5);
    q.push(3);
    q.push(4);
    q.push(31);
    q.push(41);
    q.push(12);
    q.push(2);
    q.display();
    q.pop();
    q.display();
    q.push(6);
    q.push(16);
    q.display(); 
    q.pop();
    q.display();
    q.push(16);
    q.display();
    return 0;
}