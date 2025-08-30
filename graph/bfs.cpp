#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void bfs(vector<vector<int>> &adj,int s)
{
    int size=adj.size();
    vector<bool>vis(size,false);
    queue<int>q;
    vis[s]=true;
    q.push(s);

    
    vector<int>ans;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        ans.push_back(curr);

        for(auto it : adj[curr])
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


}
int main()
{
    fast_io;

    int totalNode=5;
    // vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<vector<int>>adj(totalNode);

    adj[0]={1,4};
    adj[1]={0,2,3};
    adj[2]={1};
    adj[3]={1};
    adj[4]={0};


    int source=0;
    bfs(adj,source);
    return 0;
}