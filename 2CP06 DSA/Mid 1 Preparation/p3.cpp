#include <iostream>
using namespace std;
template <class T>
class stack
{
    int size;
    int top = -1;
    T *arr;
public:
    stack(int s) : size(s)
    {
        arr = new T[s];
    }
    void display()
    {
        int i = 0;
        while (i <= top)
        {
            cout << arr[i] << "|";
            i++;
        }
    }
    void push(T val)
    {
        try
        {
            if (top == size - 1)
            {
                throw val;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }
        catch (T val)
        {
            cout << "Stack is Full" << endl;
        }
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
            return NULL;
        }
        return arr[top--];
    }
    ~stack()
    {
        delete[] arr;
    }
};
int main(void)
{

    int choice, n;
    double temp;

    cout << "Length of Stack : ";
    cin >> n;
    stack<double> q(n);

    cout << "1. Push\n"
         << "2. Display\n"
         << "3. POP\n"
         << "4. exit\n";
    while (true)
    {
        cout << endl
             << "Choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> temp;
            q.push(temp);
            q.display();
            break;
        case 2:
            q.display();
            break;
        case 3:
            cout << q.pop() << endl;
            q.display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}