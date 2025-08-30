#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void insertionSort(int arr[],int n)
{
     for(int i=1;i<n;i++)
     {
         int key=arr[i];
         int j=i-1;
         while(j>=0  && arr[j]>key)
         {
            arr[j+1]=arr[j];
            j--;
         }
         arr[j+1]=key;
     }
}
int main()
{
    fast_io;

    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    insertionSort(v,n);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}