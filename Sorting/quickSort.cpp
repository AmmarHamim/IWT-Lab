#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int partition(int arr[],int low,int high)
{
    int pivot=arr[high]; // Choose the last element as pivot
    int i=low-1; // Index of smaller element
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i+1],arr[high]); // Swap arr[i+1] and arr[high] (or pivot)
    return i+1; // Return the index of the pivot
}
void quickSort(int arr[],int low,int high)
{
    if(low>=high)return;
    int pivotindx=partition(arr,low,high);
    quickSort(arr,low,pivotindx-1);
    quickSort(arr,pivotindx+1,high);
}
int main()
{
    fast_io;

    int arr[]={11,5,4,3,2,1,12,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Quick sort function
    quickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}