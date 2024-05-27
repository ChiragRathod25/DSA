#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valueWeight(vector<float> a, vector<float> b)
{
    cout << a[2] << " " << b[2] << endl;
    return a[2] < b[2];
}

int main()
{
    vector<vector<float>> ob(10);
    cout << "Enter query : ";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cout << "Enter value and weight : ";
        float v, w;
        cin >> v >> w;
        ob[i].push_back(v);
        ob[i].push_back(w);
        ob[i].push_back(v/w);
    }
    ob.resize(q);
    sort(ob.begin(), ob.end(), valueWeight);
    cout <<"Out of sort";

    for (int i = 0; i < q; i++)
    {
        cout << ob[i][0] << " " << ob[i][1] << endl;
    }

    return 0;
}