#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int position;
    cin >> position;
    vec.erase(vec.begin() + position - 1);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    int a, b;
    cin >> a >> b;
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    return 0;
}