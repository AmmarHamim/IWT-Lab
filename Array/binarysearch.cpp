#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    fast_io;

    int n,val;cin>>n>>val;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==val)
        {
            cout<<"Found"<<endl;
            return 0;
        }
        if(arr[mid]<val) r=mid-1;
        else l=mid+1;
    }
    cout<<"NOt found"<<endl;
    return 0;
}