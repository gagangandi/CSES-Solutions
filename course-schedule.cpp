#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    vector<int>indeg(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : graph[node])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                q.push(it);
            }
        }
    }
    if(topo.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<topo[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}