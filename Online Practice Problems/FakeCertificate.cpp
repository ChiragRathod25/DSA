// codechef https://www.codechef.com/START125D/problems/FKMC


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    string s;
    int count;
    while (t--) {
        int n;
        cin >> n;
        cin >> s;
        count = 0;
        cout<<s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] - 48 == 1) {
                cout<<"i: "<<i;
                int temp_count = 1;
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[i] - 48 == 0) {
                        temp_count++;
                    }
                    if(s[i]-48==1){
                        i=j;
                        temp_count++;
                        break;
                    }
                }
                if(temp_count>count){
                    count=temp_count;
                }
            }
        }
        if (count == 0) {
            count = s.length();
        }
        cout << count << endl;
    }
}