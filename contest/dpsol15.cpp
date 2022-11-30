#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>grid;
int n,m;
int dp[1001][1001];
int rec(int i, int j){
    if(i>=n || j>=m)return 1e9;
    if(i==n-1 &&  j==m-1) return max(1LL,1LL-grid[i][j]);
    if(dp[i][j]!=-1)return dp[i][j];
    return  dp[i][j]= max(1LL,min(rec(i+1,j),rec(i,j+1))-grid[i][j]);
}
void solve()
{
    cin>>n>>m;
    grid.clear();
    grid.resize(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>grid[i][j];
      
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0);
    cout<<ans<<endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}