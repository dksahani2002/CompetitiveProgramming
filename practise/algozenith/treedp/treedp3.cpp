#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans;
int dp[100001][2];
vector<vector<int>>g;
vector<int>w;
void indfs(int node,int par){
        dp[node][1]=w[node];
        dp[node][0]=0;
        for(auto v:g[node]){
            if(v!=par){
               indfs(v,node);
               dp[node][1]+=dp[v][0];
               dp[node][0]+=max(dp[v][1],dp[v][0]);
            }
        }  
}
void solve()
{
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    g.resize(n+1);
    w.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    w[0]=0;
    for(int i=0;i<n;i++){
        cin>>w[i+1];
    }
    ans=INT_MIN;
    indfs(1,0);
    ans=max(dp[1][0],dp[1][1]);
    cout<<ans<<" ";
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