#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void dfs(vector<vector<int>>&adj,int s,vector<bool>&vis,vector<int>&ans)
{
    vis[s]=true;
    ans.push_back(s);
    for(auto it: adj[s])
    {
        if(!vis[it])dfs(adj,it,vis,ans);
    }
}
int main()
{
    fast_io;

    int totalNode=5;
    vector<vector<int>>adj(totalNode);

    adj[0]={1,4};
    adj[1]={0,2,3};
    adj[2]={1};
    adj[3]={1};
    adj[4]={0};


    int source=0;
    int sz=adj.size();
    vector<bool>vis(sz,false);
    vector<int>ans;
    dfs(adj,source,vis,ans);

    for(auto u:ans)
    {
        cout<<u<<" ";
    }
    return 0;
}