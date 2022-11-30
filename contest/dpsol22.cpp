#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<string>grid; 
int dp[501][501][501];
int mod=1e9+7;
int rec(int si, int sj, int ei , int ej){

    if(si<0 || si>=n || sj<0 || sj>=m || ei<0 || ei>=n || ej<0 || ej>=m || si>ei || sj>ej )return 0;
    if(grid[si][sj]!=grid[ei][ej])return 0;
    if(abs(si-ei+sj-ej)<=1)return 1;
    if(dp[si][sj][ei]!=-1)return dp[si][sj][ei];
    int ans=0;
    ans+=rec(si+1,sj,ei-1,ej);
    ans+=rec(si+1,sj,ei,ej-1);
    ans+=rec(si,sj+1,ei,ej-1);
    ans+=rec(si,sj+1,ei-1,ej);
    return  dp[si][sj][ei]=ans%mod;
}
void solve()
{
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,n-1,m-1)<<endl;
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