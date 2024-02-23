// link : https://www.codechef.com/problems/TRANCST
#include <bits/stdc++.h>
using namespace std;
int cost(int x)
{
  return pow(2,x);
}
int nine_check(string temp){
  for (int i = 0; i < temp.length(); i++){
    if (((int)temp[i] - 48) == 1&&(((int)temp[i+1]-48)==0)) {
      for (int j = i + 1; j < temp.length(); j++)
      {
        if (((int)temp[j] - 48) == 1)
        {
          return 1;
        }
      }
    }
  }
return 0;
}

string get_binary(int n) {
    string binary;
    while (n != 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main(void)
{
  int t, n;
  cin >> t;

  while (t--)
  {
    cin >> n;
    int x = 0;
    if (!nine_check(get_binary(n)))
    {
      cout << x << endl;
    }
    else
    {
      int ary_cost = cost(x);
      int total_cost = n + ary_cost;
      while (true)
      {
        if (!nine_check(get_binary(total_cost)) == 1)
          break;
        ++x;
        ary_cost = cost(x);
        total_cost = n + ary_cost;
        // cout<<total_cost<<" "<<get_binary(total_cost)<<endl;
      }
      cout << ary_cost << endl;
    }
  }
  return 1;
}