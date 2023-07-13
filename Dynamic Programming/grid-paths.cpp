#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int main()
{
    ll n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>>ways(n,vector<ll>(n));
    if(grid[0][0]=='*')
    {
        cout<<0;
    }
    else
    {
        // ways[0][0]=1;
        // for(ll i=0;i<n;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //     {
        //         if(grid[i][j]=='.' && i-1>=0)
        //         ways[i][j]=(ways[i][j]+ways[i-1][j])%mod;
        //         if(grid[i][j]=='.' && j-1>=0)
        //         ways[i][j]=(ways[i][j]+ways[i][j-1])%mod;
        //     }
        // }
        // cout<<ways[n-1][n-1];
        vector<ll>prev(n,0);
        prev[0]=1;
        for(int i=1;i<n;i++)
        {
            if(grid[0][i]=='.')
            {
                prev[i]=1;
            }
            else
            {
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<ll>curr(n);
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='.' && j-1>=0)
                curr[j]=(curr[j]+curr[j-1])%mod;
                if(grid[i][j]=='.')
                curr[j]=(curr[j]+prev[j])%mod;
            }
            prev=curr;
        }
        cout<<prev[n-1];
    }
}