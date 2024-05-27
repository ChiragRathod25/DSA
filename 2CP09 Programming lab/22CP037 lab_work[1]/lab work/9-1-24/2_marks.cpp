#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(int argv, char *argc[])
{
    ifstream in(argc[1]);
    int arr[100], n = 0;
    while (!in.eof())
    {
        int temp;
        in >> temp;
        if (!in.eof())
        {
            arr[n] = temp;
            n++;
        }
    }
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += arr[i];
    }
    avg = avg / (float)n;
    float deviation = 0;
    for (int i = 0; i < n; i++)
    {
        float temp;
        temp = (avg - arr[i]);
        temp = temp * temp;
        deviation += temp;
    }
    deviation = deviation / n;
    float sd = sqrt(deviation);
    cout << "Mean is " << avg << endl
         << "SD is " << sd << endl;
}