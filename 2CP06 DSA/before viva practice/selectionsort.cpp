#include<iostream>
using namespace std;
int main(){
    int arr[]={12,54,45,78,0,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
       for(int j=i+1;j<size;j++){
        if(arr[i]>arr[j]){
            swap(arr[i],arr[j]);
        }
       }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}