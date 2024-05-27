#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> ob;
    cout << "Enter number of string : ";
    int n;
    cin >> n;
    cout << "Enter string : ";
    while(n--)
    {
        string s;
        cin >> s;
        ob[s]++;
    }
    map<string, int> :: iterator iter;
    for(iter = ob.begin(); iter != ob.end(); iter++)
        cout << iter->first << " " << iter->second << endl;
    return 0;
}