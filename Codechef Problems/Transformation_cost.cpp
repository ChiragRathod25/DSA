// link : https://www.codechef.com/problems/TRANCST
#include <bits/stdc++.h>
using namespace std;
int cost(int x)
{
  if (x == 0 || x == 1)
  {
    return 1;
  }
  return 2 * cost(x - 1);
}
int nine_check(string temp)
{
  int flag = 0;
  for (int i = 0; i < temp.length(); i++)
  {
    if (((int)temp[i] - 48) == 1)
    {
      bool first_verification = false;
      bool final_verification = false;
      for (int j = i + 1; j < temp.length(); j++)
      {
        if (((int)temp[j] - 48) == 0)
        {
          first_verification = true;
        }
        if (first_verification && ((int)temp[j] - 48) == 1)
        {
          final_verification = true;
          flag = 1;
          return flag;
        }
      }
    }
  }
  return flag;
}
string get_binary(int n)
{
  stack<int> s;
  while (n != 1)
  {
    s.push(n % 2);
    n = n / 2;
  }
  s.push(1);
  string binary;
  while (!s.empty())
  {
    binary += s.top() + 48;
    s.pop();
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
        cout << total_cost << " " << get_binary(total_cost) << endl;
      }
      cout << ary_cost << endl;
    }
  }
  return 1;
}