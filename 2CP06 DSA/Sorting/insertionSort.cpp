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
    cout<<"insertion sort : "<<endl;
    display(arr,arrSize);

    for(int i=1;i<arrSize;i++){
        int j=i-1;
        int current=arr[i];
        while(j>=0&&arr[j]>current){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
        cout<<"Pass "<<i<<" : ";
        display(arr,arrSize);

    }

    display(arr,arrSize);
    
    return 0;
}