#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of string : ";
    cin >> n;
    set<string> s;
    cout << "Enter string : ";
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << "Which string you want to search : ";
    string temp;
    cin >> temp;
    if(s.find(temp) != s.end())
        cout << "yes";
    else
        cout << "no";

    return 0;
}