#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> ob;

    int q;
    cout << "Enter number of query : ";
    cin >> q;

    while (q--)
    {
        int type;
        cout << "Enter type : ";
        cin >> type;

        string name;
        int marks;
        cout << "Enter name : ";
        cin >> name;
        if (type == 1)
        {
            cout << "Enter marks : ";
            cin >> marks;
        }

        if (type == 1)
            ob[name] += marks;
        else if (type == 2)
            ob[name] = 0;
        else if (type == 3)
            cout << "Marks : " << ob[name] << endl;
        else
            cout << "Invalid choice" << endl;
    }

    return 0;
}