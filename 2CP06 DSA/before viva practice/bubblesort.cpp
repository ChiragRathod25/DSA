#include<iostream>
using namespace std;
int main(){
    int arr[]={12,54,45,78,0,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}