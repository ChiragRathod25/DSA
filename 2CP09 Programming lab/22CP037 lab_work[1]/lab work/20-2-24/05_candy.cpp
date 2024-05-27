#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of bags : ";
    cin >> n;
    multiset<int> s;
    cout << "Enter number of candy in each beg : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    int k;
    cout << "Enter time : ";
    cin >> k;
    int total_candy = 0;
    multiset<int>::iterator iter;
    for (int i = 0; i < k; i++)
    {
        iter = s.end();
        iter--;
        int temp = *iter;
        total_candy += temp;
        s.erase(iter);
        temp = temp/2;
        s.insert(temp);
    }
    cout << "Total candy eated : " << total_candy << endl;
    return 0;
}