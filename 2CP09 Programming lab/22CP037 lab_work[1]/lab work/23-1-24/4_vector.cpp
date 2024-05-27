#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(2);
    v.push_back(10);
    v.push_back(11);
    v.pop_back();
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}