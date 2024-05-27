#include <iostream>
#include <algorithm>
#include <vector>
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
    cout << "Enter target : ";
    cin >> target;
    map<int, int>::iterator iter1, iter2;
    for (iter1 = m.begin(); iter1 != m.end(); iter1++)
    {
        iter2 = m.find(target - iter1->first);
        if (iter2 != m.end() && iter1->first <= iter2->first)
            cout << iter1->second << " " << iter2->second << endl;
    }

    return 0;
}



/*

1 2 3 4 5 7 6 5

5

*/