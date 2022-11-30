#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,k;
int dp[2001][2][2002];
int rec(int i, int col,int left){
    if(left<0)return 0;
    if(i>=n)return left==0;
    if(dp[i][col][left]!=-1)return dp[i][col][left];
    if(i==0)return dp[i][col][left]=(m*rec(i+1,col,left))%mod;
    int ans=rec(i+1,col,left);
    ans+=((m-1)*rec(i+1,1-col,left-1))%mod;
    return  dp[i][col][left]= ans%mod;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int l=0;l<=k;l++)dp[i][j][l]=-1;
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