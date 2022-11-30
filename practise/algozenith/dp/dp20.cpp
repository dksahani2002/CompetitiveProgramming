#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,k;
// vector<vector<int>>g;
int g[201][201];
int dp[201][201][401];
int rec(int i, int j,  int left){
    if(i>=n || j>=m || left<0)return 0;
    if(i==n-1 && j==m-1){
        if(g[i][j]==1)return left>0;
        else return left>=0;
    }
    if(dp[i][j][left]!=-1)return dp[i][j][left];
    int ans=0;
    if(g[i][j]){
        if(left>0){
            ans+=rec(i+1,j,left-1)+rec(i,j+1,left-1);
        }
    }else{
            ans+=rec(i+1,j,left)+rec(i,j+1,left);

    }
    ans%=mod;
    return dp[i][j][left]= ans;
}
void solve()
{
    cin>>n>>m>>k;
    // g.clear();
    // g.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            for(int l=0;l<=k;l++){
                dp[i][j][l]=-1;
            }
        }
    }
    cout<<rec(0,0,k)<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}