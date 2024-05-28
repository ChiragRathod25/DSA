#include<iostream>
using namespace std;
int main(){
    int arr[]={12,54,45,78,0,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<size;i++){
     int j=i-1;
     int current =arr[i];
     while(arr[j]>current&&j>=0){
        arr[j+1]=arr[j];
        j--;
     }
     arr[j+1]=current;
    }
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}