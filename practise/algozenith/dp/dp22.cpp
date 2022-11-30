#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,k;
int g[101][101];
int dp[101][101][12];
int rec(int i, int j,int sum){
    if(i<0 || j<0 || j>=m)return -1e9;
    if(i==0){
        sum+=g[i][j];
        if(sum%k==0)return g[i][j];
        return -1e9;
    }
    if(dp[i][j][sum]!=-1)return dp[i][j][sum];
    int val=(sum+g[i][j])%k;
    return  dp[i][j][sum]=g[i][j]+max(rec(i-1,j-1,val),rec(i-1,j+1,val));
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;cin>>x;
            g[i][j]=x-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<=k;l++)dp[i][j][l]=-1;
        }
    }
    int ans=-1e9;
    for(int j=0;j<m;j++){
        ans=max(ans,rec(n-1,j,0));
    }
    if(ans<0){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
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