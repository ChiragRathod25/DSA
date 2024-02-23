#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n, Q;
    set<string> s;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
    }
    cout << "Enter queries :";
    cin >> Q;
    int i = 0;
    while (i++ < Q)
    {
        cout << "Enter string to search :";
        cin >> temp;
        // set<string> ::iterator it;
        auto it = s.find(temp);
        if (it != s.end())
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}