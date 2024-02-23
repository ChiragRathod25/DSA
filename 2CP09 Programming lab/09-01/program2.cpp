#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        cout<<"Enter command line argument";
        return 1;
    }

    ifstream in(argv[1]);
    int * a, i;
    float total= 0.0, mean, median;
    in>>i;
    a = new int[i];
    for(int j = 0; j<i; j++)
    {
        if(!in.eof())
        {
            in>>a[j];
            cout<<a[j]<<endl;
        }
        else{
            cout<<"Invalid"<<endl;
            return 0;
        }
        total = total + a[j];
    }
    mean = total / (float)i;
    cout<<"Mean: "<<mean<<endl;
    if(i%2 == 0)
    {
        int n1 = i/2;
        int n2 = n1+ 1;
        median = (a[n1-1] + a[n2-1])/2;
    }
    else
    {
        median = a[((i + 1)/2)-1];
    }
    cout<<"Median: "<<median<<endl;
}
