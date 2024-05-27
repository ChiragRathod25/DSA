#include <iostream>
#include <vector>
using namespace std;

int remove(vector<int> &vec)
{
    vector<int>::iterator iter = vec.begin();
    while (iter != vec.end())
    {
        if (*iter == *(iter + 1) && iter != vec.end() - 1)
            vec.erase(iter);
        iter++;
    }
    return vec.size();
}

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
    int nums = remove(vec);
    cout << "Non repeting numbers are : " << nums;

    return 0;
}