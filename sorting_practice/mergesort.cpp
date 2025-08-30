#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void mergeArr(int arr[],int low,int mid,int high)
{
    int left=low;
    int right=mid+1;

    int temp[high-low+1];
    int k=0;
    while(left<=mid&& right<=high)
    {
        if(arr[left]<arr[right])temp[k++]=arr[left++];
        else temp[k++]=arr[right++];
    }
    while(left<=mid)
    {
        temp[k++]=arr[left++];
    }
    while(right<=high)
    {
        temp[k++]=arr[right++];
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergeSort(int arr[],int low,int high)
{
    if(low>=high)return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    mergeArr(arr,low,mid,high);
}

int main()
{
    fast_io;

    int arr[]={4,3,1,2,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}