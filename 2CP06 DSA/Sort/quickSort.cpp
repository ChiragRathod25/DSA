#include<iostream>
using namespace std;
void display(int *arr,int arrSize){
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void sort(int a[],int d,int u,int s){
    if(d>=u){
        return;
    }
    int temp=d;
    int key=a[d];
    while(a[d]<=key&&d<s){
        d++;
    }
    while(a[u]>key&&u>=0){
        u--;
    }

    if(d<u){
        swap(a[d],a[u]);
    }
    else{
        swap(a[temp],a[u]);
    }
    sort(a,0,u-1,u);
    sort(a,u+1,s-1,s);

}
int main(){
    // int arr[]={10,5,25,7,50,1};
    int arr[]={201,71,44,37,29,18,4};
    
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Quick sort : "<<endl;
    display(arr,arrSize);

    sort(arr,0,arrSize-1,arrSize);
    
    display(arr,arrSize);
    return 0;
}