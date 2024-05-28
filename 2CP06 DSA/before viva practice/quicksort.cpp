#include<iostream>
using namespace std;
void quicksort(int arr[],int d,int u, int size){
    // cout<<"executed";
    if(d>=u){
        return;
    }
    int key=arr[d];
    int temp=d;
    while (arr[d]<=key&&d<size)
    {
        d++;
    }
    while (arr[u]>key&&u>=0)    
    {
       u--;
    }
    if(d<u){
        swap(arr[d],arr[u]);
    }
    else{
        swap(arr[u],arr[temp]);
    }

    quicksort(arr,0,u-1,u);
    quicksort(arr,u+1,size-1,size);
    
}
void display(int *arr,int arrsize){
    for(int i=0;i<arrsize;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int main(){
     int arr[]={201,71,44,37,29,18,4};
     int arrsize=sizeof(arr)/sizeof(arr[0]);
     display(arr,arrsize);
     quicksort(arr,0,arrsize-1,arrsize);
     display(arr,arrsize);

    return 0;
}