#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void mergeArr(int arr[],int low,int mid,int high)
{
    int temp[high-low+1];
    int left=low,right=mid+1,k=0;
    // Merge the two halves
    // Compare the elements of the two halves and store them in temp
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[k++]=arr[left++];
        }
        else
        {
            temp[k++]=arr[right++];
        }
    }
    // Copy the remaining elements of the left half
    while(left<=mid)
    {
        temp[k++]=arr[left++];
    }
    // Copy the remaining elements of the right half
    while(right<=high)
    {
        temp[k++]=arr[right++];
    }
    // Copy the sorted elements from temp back to arr
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

}

void mergeSort(int arr[],int low,int high)
{
    if(low>=high)return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid); // Sort the left half
    mergeSort(arr,mid+1,high); // Sort the right half
    mergeArr(arr,low,mid,high); // Merge the two halves
}
int main()
{
    fast_io;

    int arr[]={5,4,3,2,1,0,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}