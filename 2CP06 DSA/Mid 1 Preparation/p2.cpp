#include <iostream>
using namespace std;

class queue
{
    int size;
    int top = 0;
    int *arr;

public:
    queue(int s)
    {
        size = s;
        arr = new int[s];
        for (int i = 0; i < s; i++)
        {
            arr[i] = -1;
        }
    }
    void push(int n)
    {
        try
        {
            if (top == size)
            {
                throw n;
            }
            else
            {
                arr[top++] = n;
            }
        }
        catch (int val)
        {
            cout << "Queue is fully loaded" << endl;
        }
    }
    int pop()
    {
        if (top <= 0)
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        else
        {
            int temp = arr[0];
            for (int i = 0; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = -1;
            top--;
            return temp;
        }
    }
    void insert_index()
    {
        int val, index;
        cout << "Enter Value and Index : ";
        cin >> val >> index;
        if (index < 0 || index > size - 1)
        {
            cout << "Index out of bound" << endl;
            return;
        }
        try
        {
            if (arr[index] == -1)
            {
                arr[index] = val;
            }
            else
            {
                throw val;
            }
        }
        catch (int val)
        {
            cout << "Index is occupied" << endl;
        }
    }

    void display()
    {
        int i = 0;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    ~queue()
    {
        delete[] arr;
    }
};
int main(void)
{

    int choice, n, temp;
    cout << "Length of Queue : ";
    cin >> n;
    queue q(n);
    cout << "1. Push\n"
         << "2. Display\n"
         << "3. POP\n"
         << "5. Insert at index\n"
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
            q.insert_index();
            q.display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}