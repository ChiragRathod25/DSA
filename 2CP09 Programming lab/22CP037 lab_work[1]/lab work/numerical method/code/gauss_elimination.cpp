#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noe; // number of equation
    cout << "Enter number of equation : ";
    cin >> noe;
    float A[noe][noe + 1];
    cout << "Enter matrix : ";
    for (int i = 0; i < noe; i++)
        for (int j = 0; j < noe + 1; j++)
        {
            float temp;
            cin >> temp;
            A[i][j] = temp;
        }

    for (int i = 0; i < noe; i++) // i for column
    {
        for (int j = i + 1; j < noe; j++) // j for row
        {
            if (A[i][i] != 0)
            {
                float ratio = (float)A[j][i] / (float)A[i][i];
                for (int k = i; k < noe + 1; k++) // k to implement operation for whole row representing column
                {
                    A[j][k] = A[j][k] - (ratio * A[i][k]);
                }
            }
        }
    }

    float ans[noe] = {0};
    for (int i = noe - 1; i >= 0; i--)
    {
        float sum = 0;
        for (int j = noe; j > i; j--)
        {
            if(j == noe)
            {
                sum += A[i][j];
                continue;
            }
            sum -= ans[j] * A[i][j];
        }
        ans[i] = sum/A[i][i];
    }

    for(int i = 0; i < noe; i++)
        cout << ans[i] << " ";

    return 0;
}