#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<int, string> m;
    string s;
    cout << "Enter string : ";
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        set<char> st;
        st.insert(s[i]);
        int j;
        for(j = i + 1; j < s.size(); j++)
        {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j]);
            }
            else
            {
                break;
            }
        }
        m[st.size()] = s.substr(i, j);
    }
    cout << "Longest substring without repeating characters : " << m.rbegin()->second << endl;
}