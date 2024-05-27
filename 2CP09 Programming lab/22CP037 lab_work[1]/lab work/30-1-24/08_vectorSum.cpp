#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter array : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int target;
    cin >> target;

    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec.size(); j++)
        {
            if(vec[i] + vec[j] == target)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}