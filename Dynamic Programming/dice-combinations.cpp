#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main()
{
    ll n;
    cin>>n;
    vector<ll>dp(n+1,-1);
    dp[0]=1;
    for(ll i=1;i<=n;i++)
    {
        ll ans=0;
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
            ans=(ans+dp[i-j])%mod;
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
}