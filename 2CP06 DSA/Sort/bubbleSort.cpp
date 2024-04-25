#include<iostream>
using namespace std;
void display(int *arr,int arrSize){
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int main(){
    int arr[]={10,5,25,7,50,1};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    // cout<<arrSize;
    
    display(arr,arrSize);
    for(int i=0;i<arrSize-1;i++){
        for(int j=0;j<arrSize-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
        cout<<"Pass "<<i+1<<" : ";
        display(arr,arrSize);
    }

    display(arr,arrSize);
    
    return 0;
}