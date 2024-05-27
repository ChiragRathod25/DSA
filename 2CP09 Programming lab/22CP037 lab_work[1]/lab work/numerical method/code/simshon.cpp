// write c++ program to evaluating definite integral of given function using trapzoidal rule of method

#include <iostream>
#include <math.h>

float f(float x) { return (1 / (1 + pow(x, 2))); }

using namespace std;
int main()
{
    float l, u, integration = 0.0, stepSize, k;
    int i, subInterval;

    cout << "Enter lower limit of integration: ";
    cin >> l;
    cout << "Enter upper limit of integration: ";
    cin >> u;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;
    stepSize = (u - l) / subInterval;

    integration = f(l) + f(u);

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = l + i * stepSize;
        integration = integration + 2 * (f(k));
    }

    integration = integration * stepSize / 2;

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}