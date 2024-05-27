#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map<int, int> m;
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter array : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m[temp] = i;
    }
    int target;
    cout << "Enter target :";
    cin >> target;

    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        int remaining = target - it->first;
        if (m.find(remaining) != m.end() && it->second < m[remaining])
        {
            cout << "Pair found at index " << it->second << " and " << m[remaining] << endl;
        }
    }
    return 0;
}