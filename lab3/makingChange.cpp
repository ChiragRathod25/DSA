#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
      int n,temp;
     cin>>n;

    vector<int> availableChanges;
    for(int i=0;i<n;i++){
        cin>>temp;
        availableChanges.push_back(temp);
    }
    sort(availableChanges.begin(),availableChanges.end(),greater<int>());

    int amount;
    cin >> amount;

    temp = amount;
    map<int, int> ans;


    for (int i = 0; i <availableChanges.size(); i++)
    {
            int val = availableChanges[i];
            int freq = temp / availableChanges[i];
            ans[val] = freq;
            temp = temp - (val * freq);
    }

    // cout << "Remaining : " << temp << endl;
    if (temp != 0)
    {
        cout << "Change is not possible" << endl;
    }
    else
        for (auto it : ans)
        {
            if (it.second != 0)
                cout << it.first << " " << it.second << endl;
    }
    return 0;
}