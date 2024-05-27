#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(2);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}