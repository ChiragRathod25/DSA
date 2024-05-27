#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of string : ";
    cin >> n;
    set<string> s1;
    multiset<string> s2;
    cout << "Enter string : ";
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        s1.insert(temp);
        s2.insert(temp);
    }

    cout << "From set" << endl;
    set<string>::iterator iter1;
    for (iter1 = s1.begin(); iter1 != s1.end(); iter1++)
    {
        cout << *iter1 << " ";
    }

    cout << endl << "From multiset" << endl;
    multiset<string>::iterator iter2, iter3 = s1.begin();
    for (iter2 = s2.begin(); iter2 != s2.end(); iter2++)
    {
        if (iter2 != s2.begin())
        {
            if (*iter2 != *iter3)
                cout << *iter2 << " ";
        }
        else
        {
            cout << *iter2 << " ";
        }
        iter3 = iter2;
    }

    return 0;
}