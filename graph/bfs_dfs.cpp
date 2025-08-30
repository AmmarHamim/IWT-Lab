#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void bfs(vector<vector<int>>&adj,vector<bool>&vis,int sz,int s)
{
    queue<int>q;
    vis[s]=true;
    q.push(s);

    vector<int>ansb;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        ansb.push_back(curr);

        for(auto it:adj[curr])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q.push(it);
            }
        }
         
    }

    for(auto u:ansb)
    {
        cout<<u<<" ";
    }
    cout<<endl;

}
void dfs(vector<vector<int>>&adj,vector<bool>&vis,int s,vector<int>&ansd)
{
    vis[s]=true;
    ansd.push_back(s);
    for(auto it:adj[s])
    {
        if(!vis[it])
        dfs(adj,vis,it,ansd);
    }
}
int main()
{
    fast_io;

    vector<vector<int>>adj(5);
    adj[0]={2,3,1};
    adj[1]={0};
    adj[2]={0,4};
    adj[3]={0};
    adj[4]={2};

    int sz=adj.size();
    vector<bool>vis(sz,false);
    vector<bool>visd(sz,false);
    vector<int>ansd;
    int s=0;
    bfs(adj,vis,sz,s);
    dfs(adj,visd,s,ansd);
    for(auto u:ansd)
    {
        cout<<u<<" ";
    }

    return 0;
}