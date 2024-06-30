#include <bits/stdc++.h>
using namespace std;
void alphaHill(int n)
{
    for (int i = 1; i <= n; i++)
    {

        char currentChar = 'A';
        int gap = 2 * (n - i);
        for (int j = 1; j <= gap; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << currentChar++ << " ";
        }
 
        currentChar--;
        currentChar--;
        for (int j = i; j > 1; j--)
        {
            cout << currentChar-- << " ";
        }
        for (int j = 1; j <= gap; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
}
int main()
{
    alphaHill(3);
}