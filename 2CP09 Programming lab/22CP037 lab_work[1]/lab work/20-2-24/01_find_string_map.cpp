#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of string : ";
    cin >> n;
    unordered_map<string, int> m;
    cout << "Enter string : ";
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        m.insert(make_pair(temp, i));
    }
    cout << "Which string you want to search : ";
    string temp;
    cin >> temp;
    if(m.find(temp) != m.end())
        cout << "yes";
    else
        cout << "no";
    return 0;
}