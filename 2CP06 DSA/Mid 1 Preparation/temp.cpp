#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class stack {
    int size;
    char *arr;
    int top;

public:
    stack(int sz) {
        size = sz;
        arr = new char[size];
        top = -1;
    }

    ~stack() {
        delete[] arr;
    }

    void push(char temp) {
        arr[++top] = temp;
    }

    char pop() {
        return arr[top--];
    }

    char get_top() {
        if (top != -1)
            return arr[top];
        else
            return '\0';
    }
};

int priority(char sign) {
    if (sign == '+' || sign == '-') {
        return 1;
    } else if (sign == '*' || sign == '/') {
        return 2;
    } else if (sign == '^') {
        return 3;
    }
    return 0;
}

int main(void) {
    char str1[100], str2[100], temp;

    stack s(100);
    cout << "Enter String : ";
    cin >> str1;

    int j = 0;
    for (int i = 0; i < strlen(str1); i++) {
        temp = s.get_top();

        if (isalnum(str1[i])) {
            str2[j++] = str1[i];
        } else {
            while (priority(temp) > priority(str1[i]) ||( (priority(temp) == priority(str1[i]) && str1[i] != '^'))) {
                str2[j++] = s.pop();
                temp = s.get_top();
            }
            s.push(str1[i]);
        }
    }

    while (s.get_top() != '\0') {
        str2[j++] = s.pop();
    }

    str2[j] = '\0';

    cout << "Postfix expression: " << str2 << endl;

    return 0;
}
