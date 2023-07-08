#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    vector<ll>indeg(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    vector<ll>ways(n+1);
    ways[1]=1;
    queue<ll>q;
    for(ll i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it : graph[node])
        {
            ways[it]=(ways[it]+ways[node])%mod;
            indeg[it]--;
            if(indeg[it]==0)
            {
                q.push(it);
            }
        }
    }
    cout<<ways[n]<<endl;
}