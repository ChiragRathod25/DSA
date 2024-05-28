#include<iostream>
#include<algorithm>
using namespace std;
int binarysearch(int arr[],int l,int r,int value){
    if(l>r) return -1;
    int mid=(l+r)/2;
    if(arr[mid]==value) return value;
    if(value>arr[mid]) return binarysearch(arr,mid+1,r,value);
    else return binarysearch(arr,l,mid-1,value);
    return -1;
}
int main(){
    int arr[]={12,54,45,78,0,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+size);

    cout<<"3 search : "<<binarysearch(arr,0,size-1,3)<<endl;
    cout<<"12 search : "<<binarysearch(arr,0,size-1,12)<<endl;
}