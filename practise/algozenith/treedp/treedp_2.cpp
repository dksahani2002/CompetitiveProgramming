#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
vector<vector<int>>g;
vector<vector<int>>dp;
int ans;
void dfs(int node,int par){
    dp[node][0]=1;
    int cntpath=0;
    for(auto v:g[node]){ 
        if(v!=par){
            dfs(v,node);
            for(int j=1;j<=k;j++){
                cntpath+=dp[v][j-1]*dp[node][k-j];
            }
            for(int j=1;j<=k;j++){
                dp[node][j]+=dp[v][j-1];
            }
        }
    }
    ans+=cntpath;
}
void solve()
{
    int n;cin>>n>>k;
    g.resize(n+1);
    dp.assign(n+1,vector<int>(k+1,0));
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=0;
    dfs(1,0);  
    cout<<ans<<endl;
    g.clear();
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}