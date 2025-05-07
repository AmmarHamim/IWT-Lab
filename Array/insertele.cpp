#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    fast_io;

    int n,k,val;cin>>n>>k>>val;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(k>=n+1 || k<0)
    {
        cout<<"Invalid index"<<endl;
        return 0;
    }
    for(int i=n;i>=k;i--)
    {
        arr[i]=arr[i-1];
    }

    arr[k]=val;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}