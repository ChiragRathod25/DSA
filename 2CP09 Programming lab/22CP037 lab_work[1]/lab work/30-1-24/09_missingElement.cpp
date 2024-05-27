#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter array : ";
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
    {
        if(i != vec[i])
        {
            cout << i << " is missing";
            break;
        }
    }
}