#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll rec(ll x, int n, int ind, vector<ll>&c, vector<vector<ll>>&dp)
{
    if(ind==n)
    {
        return 0;
    }
    if(x==0)
    {
        return 1;
    }
    if(x<0)
    {
        return 0;
    }
    if(dp[ind][x]!=-1)
    {
        return dp[ind][x];
    }
    ll ans=0;
    ans=(ans+rec(x-c[ind],n,ind,c,dp))%mod;
    ans=(ans+rec(x,n,ind+1,c,dp))%mod;
    return dp[ind][x]=ans;
}
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>c(n);
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    //vector<vector<ll>>dp(n,vector<ll>(x+1,-1));
    vector<ll> prev(x+1,0) , curr(x+1,0);
    prev[0] = curr[0] = 1;
    // for(ll i=0;i<n;i++)
    // {
    //     dp[i][0]=1;
    // }
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=1;j<=x;j++)
        {
            ll ans=0;
            if(j-c[i]>=0)
            {
                ans=(ans+curr[j-c[i]])%mod;
            }
            if(i+1<n)
            {
                ans=(ans+prev[j])%mod;
            }
            curr[j]=ans;
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
}