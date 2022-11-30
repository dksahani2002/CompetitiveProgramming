#include <bits/stdc++.h>
using namespace std;
// typedef  long long  int
#define ll long long 
const int mod=1e9+7;
int n,m,tot_cost;
ll dp[101][101][101];
ll rec(int i, int prev, int cost){
    if(i==0){
        if(cost==0)return 1;
        return 0;
    } 
    if(dp[i][prev][cost]!=-1)return dp[i][prev][cost];
    ll ans=0;
    for(int j=1;j<=m;j++){
        ans+=rec(i-1,j>prev?j:prev,cost-(j>prev));
        ans%=mod;
    }
    return dp[i][prev][cost]=ans%mod;
}
void solve()
{
    cin>>n>>m>>tot_cost;
    ll ans=0;
    ans=rec(n,0,tot_cost);
    cout<<ans<<endl;
}
signed main()
{
    int t;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while (t--)
    {
        solve();
    }
}