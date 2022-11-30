#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
vector<vector<int>>g;
// vector<vector<int>>dp;
vector<int>w;
int dp[100100][2];
void dfs(int node,int par){
    dp[node][1]=w[node];
    dp[node][0]=0;
    for(auto v:g[node]){ 
        if(v!=par){
            dfs(v,node);
            dp[node][1]+=dp[v][0];
            dp[node][0]+=max(dp[v][1],dp[v][0]);
        }
    }
}
void solve()
{
    int n;cin>>n;
    w.resize(n+1);
    g.resize(n+1);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);  
    cout<<max(dp[1][1],dp[1][0])<<endl;
    g.clear();
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}