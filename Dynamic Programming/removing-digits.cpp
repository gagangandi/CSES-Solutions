#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll rec(ll n, vector<ll>&dp)
{
    if (n == 0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    ll k = n;
    ll ans=INT_MAX;
    while (k)
    {
        if(k%10!=0)
        ans=min(ans,1+rec(n-(k%10),dp));
        k = k / 10;
    }
    return dp[n]=ans;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll>dp(n+1,-1);
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        ll temp=i;
        ll ans=INT_MAX;
        while(temp)
        {
            if(i>=temp%10 && temp%10!=0)
            ans=min(ans,1+dp[i-(temp%10)]);
            temp=temp/10;
        }
        dp[i]=ans;
    }
    cout<<dp[n];
}