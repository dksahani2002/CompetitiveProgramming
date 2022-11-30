#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
int n,m,k;
int dp2[101][101][12];
int rec(int i, int j,int sum){
    if(i>=n || j>=m || j<0)return -1e9;
    if(dp2[i][j][sum%k]!=-1)return dp2[i][j][sum%k];
    if(i==n-1){ 
        if((sum+dp[i][j])%k==0)return dp[i][j];
        return -1e9;
    }
    int res=-1e9;
    res=max(res,dp[i][j]+rec(i+1,j-1,(sum+dp[i][j])%k));
    res=max(res,dp[i][j]+rec(i+1,j+1,(sum+dp[i][j])%k));
    return  dp2[i][j][sum%k]= res;
}
void solve()
{
    
    cin>>n>>m>>k;
    // dp.clear();
    dp.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char c;cin>>c;dp[i][j]=c-'0';
        };
    int ans=-1;
    
    // memset(dp2,-1,sizeof(dp2));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<12;k++)dp2[i][j][k]=-1;
    for(int j=0;j<m;j++){
       int val=rec(0,j,0);
        ans=max(ans,val);
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