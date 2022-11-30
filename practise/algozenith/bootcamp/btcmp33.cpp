#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<int>v;
int dp[1000100];
int rec(int i){
    if(i>=v.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=rec(i+1);
    ans=max(ans,v[i]+rec(i+2));
    return  dp[i]= ans;
}
void solve()
{
    int n;cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        dp[i]=-1;
    }
    dp[n]=-1;
    cout<<rec(0)<<endl;
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}