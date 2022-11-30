#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
vector<int>v,pf;
int dp[501][501];
int rec(int l, int r){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1e9;
    for(int i=l;i<r;i++){
        int left=rec(l,i);
        int right=rec(i+1,r);
        int val=((pf[i]-((l)?pf[l-1]:0))%100)*((pf[r]-pf[i])%100);
        ans=min(ans, val+left+right);
    }
    return  dp[l][r]= ans;
}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n);
    pf.clear();
    pf.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        if(i)pf[i]=pf[i-1]+v[i];
        else pf[i]=v[i];
    }
    cout<<rec(0,n-1)<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}