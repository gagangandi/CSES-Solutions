#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>graph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<ll>dist(n+1,INT_FAST64_MAX);
    dist[1]=0;
    set<pair<ll,ll>>st;
    st.insert({0,1});
    while(st.size()>0)
    {
        auto i = *(st.begin());
        ll dis=i.first;
        ll node=i.second;
        st.erase(i);
        for(auto it : graph[node])
        {
            if(dist[it.first]>dis+it.second)
            {
                if(dist[it.first]!=INT_FAST64_MAX)
                {
                    st.erase({dist[it.first],it.first});
                }
                dist[it.first]=dis+it.second;
                st.insert({dist[it.first],it.first});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}