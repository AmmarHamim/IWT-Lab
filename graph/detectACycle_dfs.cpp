#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool dfsCycle(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfsCycle(it,node,adj,vis))return true;
        }
        else if(it!=parent)return true;
    }
    return false;
}
bool isCycle(vector<vector<int>>&adj)
{
    int sz=adj.size();
    vector<bool>vis(sz,false);
    for(int i=0;i<sz;i++)
    {
        if(!vis[i])
        {
            if(dfsCycle(i,-1,adj,vis))return true;
        }
    }
    return false;
}
int main()
{
    fast_io;

    vector<vector<int>>adj(5);
    adj[0]={2,3,1};
    adj[1]={0,2};
    adj[2]={0,1,4};
    adj[3]={0};
    adj[4]={2};

    if(isCycle(adj))cout<<"Cycle Detected!"<<endl;
    else cout<<"No Cycle"<<endl;

    return 0;
}