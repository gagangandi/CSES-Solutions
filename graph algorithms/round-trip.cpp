#include<bits/stdc++.h>
using namespace std;
#define ll long long

void findpath(ll k, vector<vector<ll>>&graph, vector<ll>parent)
{
    vector<ll>path;
    path.push_back(k);
    ll a=parent[k];
    while(a!=k)
    {
        path.push_back(a);
        a=parent[a];
    }
    path.push_back(k);
    cout<<path.size()<<endl;;
    for(ll i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
}

ll dfs(ll node, ll par, vector<vector<ll>>&graph, vector<ll>&vis, vector<ll>&parent)
{
    vis[node]=1;
    for(auto it : graph[node])
    {
        if(!vis[it])
        {
            parent[it]=node;
            ll a=dfs(it,node,graph,vis,parent);
            if(a!=0)
            {
                return a;
            }
        }
        else
        {
            if(it!=par)
            {
                parent[it]=node;
                return it;
            }
        }
    }
    return 0;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>graph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll>vis(n+1);
    ll flag=0;
    vector<ll>parent(n+1);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ll k=dfs(i,-1,graph,vis,parent);
            //cout<<k;
            if(k)
            {
                flag=1;
                findpath(k,graph,parent);
                break;
            }
        }
    }
    if(flag==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}