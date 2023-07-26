#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printpath(vector<ll>&parent)
{
    ll n=parent.size()-1;
    ll k=n;
    vector<ll>ans;
    while(k!=-1)
    {
        ans.push_back(k);
        k=parent[k];
    }
    for(ll i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

ll bfs(ll start, ll end, vector<vector<ll>>&graph, vector<ll>&vis, vector<ll>&parent)
{
    vis[start]=1;
    parent[start]=-1;
    queue<pair<ll,ll>>q;
    q.push({start,1});
    while(!q.empty())
    {
        ll node=q.front().first;
        ll d=q.front().second;
        q.pop();
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,d+1});
                parent[it]=node;
                if(it==end)
                {
                    return d+1;
                }
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
    vector<ll>parent(n+1);
    ll dis=bfs(1,n,graph,vis,parent);
    if(dis)
    {
        cout<<dis<<endl;
        printpath(parent);
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}