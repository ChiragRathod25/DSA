#include<iostream>
using namespace std;
int main(){
    int arr[]={12,54,45,78,0,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int gap=size/2;gap>=1;gap/=2)
    {
        for(int j=gap;j<size;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]<arr[i]){
                   swap(arr[i+gap],arr[i]);
                }
            }
        }
    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}