#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
int dp[1001][1001];
int rec(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m )return -1e9;
    if(i==n-1 && j==m-1)return g[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]= g[i][j]+max(rec(i+1,j),rec(i,j+1));
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<rec(0,0)<<endl;
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