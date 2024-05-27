#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valueWeight(pair<int, int> a, pair<int, int> b)
{
    return (float)a.first / a.second < (float)b.first / b.second;
}

int main()
{
    vector<pair<int, int>> ob;
    cout << "Enter query : ";
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter value and weight : ";
        int v, w;
        cin >> v >> w;
        ob.push_back(make_pair(v, w));
    }
    sort(ob.begin(), ob.end(), valueWeight);
    vector<pair<int, int>>::iterator iter;
    for (iter = ob.begin(); iter != ob.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    return 0;
}