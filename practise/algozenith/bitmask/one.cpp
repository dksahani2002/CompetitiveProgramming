#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>v;
int n,m;
int dp[51][1<<10];
int rec(int i, int mask){
    if(i>=m)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=rec(i+1,mask);
    for(int j=0;j<n;j++){
        if((mask&(1<<j))==0){
            ans=max(ans,v[i][j]+rec(i+1,mask|(1<<j)));
        }
    }
    return dp[i][mask]=ans;
}
void solve()
{
    cin>>n>>m;
    vector<vector<int>>happy(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)cin>>happy[i][j];
    }
    v=happy;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}