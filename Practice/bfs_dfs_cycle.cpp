#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void bfs(vector<vector<int>>&adj,int sz,int s)
{
    vector<bool>vis(sz,false);
    queue<int>q;
    vector<int>ans;
    vis[s]=true;
    q.push(s);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        ans.push_back(curr);

        for(auto it:adj[curr])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q.push(it);
            }
        }

    }

    for(auto u:ans)
    {
        cout<<u<<" ";
    }
    cout<<endl;
}
void dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int s,int sz)
{
    vis[s]=true;
    ans.push_back(s);

    for(auto it:adj[s])
    {
        if(!vis[it])dfs(adj,vis,ans,it,sz);
    }
}
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
        if(dfsCycle(i,-1,adj,vis))return true;
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

    int sz=adj.size();
    vector<int>ansd;
    vector<bool>visd(sz,false);
    int s=0;

    bfs(adj,sz,s);
    dfs(adj,visd,ansd,s,sz);
    for(auto u:ansd)
    {
        cout<<u<<" ";
    }
    cout<<endl;

    if(isCycle(adj))cout<<"Cycle Detected!"<<endl;
    else cout<<"No Cycle"<<endl;
    return 0;
}