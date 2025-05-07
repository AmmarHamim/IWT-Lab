#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10]={3,2,3,4,5,6,7,8,9,3};
    int val=3;

    int n= sizeof(arr)/sizeof(arr[0]);
    int indx[10];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            indx[cnt++]=i;
        }
    }

    if(cnt>0)
    {
        cout<<val<<" Found at indexes: ";
        for(int i=0;i<cnt;i++)
        {
            cout<<indx[i]<<" ";
        }
    }
    else cout<<"Not Found"<<endl;

    return 0;
}