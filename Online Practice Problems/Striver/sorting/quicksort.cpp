//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int temp=partition(arr,low,high);
            quickSort(arr,low,temp-1);
            quickSort(arr,temp+1,high);
        }
        // code here
    }
    
    public:
    int partition(int arr[], int low, int high) {
    int pivotIndex = (low + high) / 2; // Choosing the middle element as pivot
    int pivotValue = arr[pivotIndex];
    int i = low, j = high;
    while (i <= j) {
        while (arr[i] < pivotValue) i++;
        while (arr[j] > pivotValue) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i; // Return the partitioning index
}
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    // scanf("%d",&T);
    // while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
   
    return 0;
}
// } Driver Code Ends