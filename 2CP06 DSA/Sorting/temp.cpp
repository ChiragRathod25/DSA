#include<iostream>

using namespace std;
static int loopcount=0;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void sort(int a[],int d, int u,int s)
{   
    loopcount++;
    if(d>=u){
        return;
    }
    int temp=d;
    int pi=a[d];
    while(1){
        cout<<"hello"<<endl;
        while (a[d]<= pi && d<s)
        {
            d++;
        }
        while(a[u]> pi && u>=0){
            u--;
        }
        if(d<u)
        {
            int t=a[d];
            a[d]=a[u];
            a[u]=t;
        }
        else{
            a[temp]=a[u];
            a[u]=pi;
            break;
        }
    }
    sort(a,0,u-1,u);
    sort(a,u+1,s-1,s);
}

int main()
{
    int arr[]={201,71,44,37,29,18,4};
    // int arr[]={10,5,25,7,50,1};
    int s=7;
    sort(arr,0,6,s);
    display(arr,s);
    cout<<loopcount<<endl;
}