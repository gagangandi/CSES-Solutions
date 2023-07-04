#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&vis, vector<vector<int>>&graph)
{
    vis[node]=1;
    for(auto it : graph[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,graph);
        }
    }
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
    vector<int>vis(n+1);
    int ans=0;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans++;
            dfs(i,vis,graph);
            if(i!=1)
            {
                v.push_back({i,i-1});
            }
        }
    }
    cout<<ans-1<<endl;
    if(v.size()>0)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
}