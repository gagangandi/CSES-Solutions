#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
void dijkstra(ll node, vector<vector<pair<ll,ll>>>&graph, vector<ll>&dist)
{
    set<pair<ll,ll>>st;
    st.insert({0,node});
    while(!st.empty())
    {
        auto it = *(st.begin());
        ll nd=it.second;
        ll dis=it.first;
        st.erase(it);
        for(auto it : graph[nd])
        {
            ll adjnode=it.first;
            ll wt=it.second;
            if(dis+wt<dist[adjnode])
            {
                if(dist[adjnode]!=INT64_MAX)
                {
                    st.erase({dist[adjnode],adjnode});
                }
                dist[adjnode]=dis+wt;
                st.insert({dis+wt,adjnode});
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>graph(n+1);
    vector<vector<pair<ll,ll>>>revgraph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        revgraph[b].push_back({a,c});
    }
    vector<ll>src(n+1,INT64_MAX);
    src[1]=0;
    vector<ll>end(n+1,INT64_MAX);
    end[n]=0;
    dijkstra(1,graph,src);
    dijkstra(n,revgraph,end);
    ll ans=INT64_MAX;
    for(ll i=1;i<=n;i++)
    {
        for(auto it : graph[i])
        {
            ans=min(ans,src[i]+end[it.first]+it.second/2);
        }
    }
    cout<<ans<<endl;
}