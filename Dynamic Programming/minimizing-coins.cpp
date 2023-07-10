#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        ll ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(i-c[j]>=0)
            ans=min(ans,1+dp[i-c[j]]);
        }
        dp[i]=ans;
    }
    cout<<(dp[x]!=INT_MAX?dp[x]:-1)<<endl;
}