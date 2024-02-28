#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int b;
    cout<<"Enter nomber of bags : ";
    cin>>b;
    vector<int> candy;
    int sum=0;
    int temp;
    cout<<"Enter the number of candy in each bag : ";
    for(int i=0;i<b;i++)
    {
        cin>>temp;
        candy.push_back(temp);
    }
    int t;
    cout<<"Enter the number of times : ";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<b;j++)
        {
            candy[j]/=2;
            sum+=candy[j];
        }
    }
    cout<<sum;
}