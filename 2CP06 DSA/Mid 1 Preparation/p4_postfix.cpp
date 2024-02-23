#include <iostream>
#include <cstring>
using namespace std;
class stack
{
    int size;
    char *arr;
    int top = -1;

public:
    stack(int size)
    {
        arr = new char[size];
    }
    void push(char temp)
    {
        top++;
        arr[top] = temp;
    }
    char pop()
    {
        return arr[top--];
    }
    char get_top()
    {
        if (top != -1)
            return arr[top];
        else return '\0';
    }
    int val_of_top(){
        return top;
    }
    void display()
    {
        int i = 0;
        while (i <= top)
        {
            cout << arr[i] << " ";
            i++;
        }
    }
    ~stack()
    {
        delete[] arr;
    }
};

int main(void)
{
    char str1[100], str2[100], temp;

    stack s(100);
    cout << "Enter String : ";
    cin >> str1;
    cout << str1 << endl;
    int j = 0;
    int i = 0;
    for (i = 0; i < strlen(str1); i++)
    {
        temp = s.get_top();
        // cout << str1[i] << " " << temp << endl;
        if (str1[i] == '+' || str1[i] == '-')
        {
            if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^')
            {
                str2[j++] = s.pop();
                s.push(str1[i]);
                    while (temp != str1[i]||temp!='\0')
                    {
                        str2[j++] = s.pop();
                        temp = s.get_top();
                    }
            }
            else
            {
                s.push(str1[i]);
            }
        }

        else if (str1[i] == '*' || str1[i] == '/')
        {
            if (temp == '*' || temp == '/' || temp == '^')
            {
                str2[j++] = s.pop();
                s.push(str1[i]);
                while (temp != str1[i])
                {
                    str2[j++] = s.pop();
                    temp = s.get_top();
                }
            }
            else
            {
                s.push(str1[i]);
            }
        }

        else if (str1[i] == '^')
        {
            if (temp == '^')
            {
                str2[j++] = s.pop();
                s.push(str1[i]);
                while (temp != str1[i])
                {
                    str2[j++] = s.pop();
                    temp = s.get_top();
                }
            }
            else
            {
                s.push(str1[i]);
            }
        }
        else
        {
            str2[j] = str1[i];
            j++;
        }
    }
    // s.display();
    while (j != i)
    {
        str2[j] = s.pop();
        j++;
    }
    str2[j] = NULL;
    cout << str2 << endl;
    return 0;
}