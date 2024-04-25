#include<iostream>
using namespace std;
void display(int *arr,int arrSize){
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    
    int a[n1];
    int b[n2]; //temp array
    
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        b[j]=arr[mid+j+1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
            arr[k]=a[i];
            i++;
            k++;
    }
    while(j<n2){
            arr[k]=b[j];
            j++;
            k++;
    }

}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={10,5,25,7,50,1};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    cout<<"Merge sort : "<<endl;
    display(arr,arrSize);
    mergesort(arr,0,arrSize-1);

    display(arr,arrSize);
    
    return 0;
}