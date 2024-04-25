#include<iostream>
#include<algorithm> 
using namespace std;
int binarySearch(int arr[],int l,int r,int value){
    if (l>r) return -1;
   int mid=(l+r)/2;
   if(arr[mid]==value) return value;
   if(value>arr[mid]) return binarySearch(arr,mid+1,r,value);
   else return  binarySearch(arr,l,mid-1,value);

    return -1;
}

int main(){
    int arr[]={201,71,44,37,29,18,4};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+arrSize);
    cout<<binarySearch(arr,0,arrSize-1,17);

    return 0;
}