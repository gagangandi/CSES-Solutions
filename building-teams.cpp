#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>&vis, vector<vector<int>>&graph, int col)
{
    vis[node]=col;
    for(auto it : graph[node])
    {
        if(vis[it]==-1)
        {
            if(dfs(it,vis,graph,!col)==false)
            {
                return false;
            }
        }
        else
        {
            if(vis[it]==col)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int>vis(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            if(dfs(i,vis,graph,0)==false)
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<vis[i]+1<<" ";
    }
    cout<<endl;
}