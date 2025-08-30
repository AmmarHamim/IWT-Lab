#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9
void dijkstra(vector<vector<pair<int,int>>>&adj,int s)
{
    int sz=adj.size();
    vector<int>dist(sz,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    dist[s]=0;
    pq.push({0,s});

    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        for(auto it:adj[node])
        {
            int adjNode=it.first;
            int w=it.second;
            if(d+w<dist[adjNode])
            {
                dist[adjNode]=d+w;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    for(int i=0;i<sz;i++)
    {
        cout<<i<<": "<<dist[i]<<endl;
    }
}
int main()
{
    fast_io;

    vector<vector<pair<int,int>>>adj(5);
    adj[0]={{1,4},{2,8}};
    adj[1]={{0,4},{4,6}};
    adj[2]={{0,8},{3,2}};
    adj[3]={{2,2},{4,10}};
    adj[4]={{3,10},{1,6}};

    int s=0;
    dijkstra(adj,s);
    return 0;
}