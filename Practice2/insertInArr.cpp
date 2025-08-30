#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void insertionArr(int arr[],int n, int k,int val)
{
    for(int i=n;i>=k;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[k-1]=val;
}
int main()
{
    fast_io;

    int n,k;cin>>n>>k;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertionArr(arr,n,k,100);
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}