//interpolation

#include <iostream>
#include <vector>
using namespace std;


vector<vector<double>> ddifferences(const vector<double> &x, const vector<double> &y)
{
    int n = x.size();
    vector<vector<double>> f(n, vector<double>(n, 0.0));


    for (int i = 0; i < n; ++i)
        f[i][0] = y[i];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            f[j][i] = (f[j + 1][i - 1] - f[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    return f;
}


double interpolate(const vector<double> &x, const vector<double> &y, double xi)
{
    int n = x.size();
    double result = 0;

    vector<vector<double>> f = ddifferences(x, y);


    result = f[0][0];
    double term = 1.0;

    for (int i = 1; i < n; ++i)
    {
        term *= (xi - x[i - 1]);
        result += f[0][i] * term;
    }

    return result;
}

int main()
{
    vector<double> x = {0, 1, 2, 3, 4};
    vector<double> y = {1, 3, 9, 27, 81};

    double xi = 2.5;

    double interpolatedValue = interpolate(x, y, xi);

    cout << "Interpolated value at x = " << xi << " is: " << interpolatedValue << endl;

    return 0;
}
