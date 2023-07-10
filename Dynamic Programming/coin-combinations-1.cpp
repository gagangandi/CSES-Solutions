#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll rec(ll x, int n, vector<ll>&c, vector<ll>&dp)
{
    if(x==0)
    {
        return 1;
    }
    if(x<0)
    {
        return 0;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+rec(x-c[i],n,c,dp))%mod;
    }
    return dp[x]=ans;
}
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>c(n);
    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
    }
    vector<ll>dp(x+1,-1);
    dp[0]=1;
    for(ll i=1;i<=x;i++)
    {
        ll ans=0;
        for(int j=0;j<n;j++)
        {
            if(i-c[j]>=0)
            {
                ans=(ans+dp[i-c[j]])%mod;
            }
        }
        dp[i]=ans;
    }
    cout<<dp[x];
}