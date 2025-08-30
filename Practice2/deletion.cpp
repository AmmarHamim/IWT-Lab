#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    fast_io;

    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=k-1;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++)
    {
        
        cout<<arr[i]<<" ";
    }

    return 0;
}