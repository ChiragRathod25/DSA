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
    cout<<"Selection sort : "<<endl;
    display(arr,arrSize);

    for(int i=0;i<arrSize;i++){
        for(int j=i+1;j<arrSize;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    display(arr,arrSize);
    
    return 0;
}