#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> m;
    int n;
    cout << "Enter number of input : ";
    cin >> n;
    cout << "Enter numbers :";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m.insert(temp);
    }

    int temp;
    multiset<int>::iterator iter;
    cout << "Enter number to delete : ";
    cin >> temp;

    cout << "Deleting first occurence" << endl;
    for (iter = m.begin(); iter != m.end(); iter++)
        if (*iter == temp)
            break;
    if (iter != m.end())
        m.erase(iter);
    for (iter = m.begin(); iter != m.end(); iter++)
        cout << *iter << " ";

    cout << endl
         << "Deleting all occurence" << endl;
    m.erase(temp);
    for (iter = m.begin(); iter != m.end(); iter++)
        cout << *iter << " ";
}