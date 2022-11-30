#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m,ans=0;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>dp[i][j],ans=max(ans,dp[i][j]);
    for(int j=0;j<m;j++)
        for(int i=1;i<n;i++){
            dp[i][j]+=(dp[i][j])?min({(i)?dp[i-1][j]:0,(j)?dp[i][j-1]:0,(i && j)?dp[i-1][j-1]:0}):0;
            ans=max(ans,dp[i][j]*dp[i][j]);
        }
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