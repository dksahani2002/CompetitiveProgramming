#include <bits/stdc++.h>
using namespace std;
#define int long long
int sz[100001];
void dfs(int node, int par, int lev, vector<vector<int>>&g,vector<int>&w,vector<int>&dp){
    dp[1]+=w[node]*lev;
    sz[node]=w[node];
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node,lev+1,g,w,dp);
            sz[node]+=sz[v];
        }
    }
}
void dfs2(int node, int par,vector<vector<int>>&g,vector<int>&dp){
    for(auto v:g[node]){
        if(v!=par){
            dp[v]+=dp[node]+sz[1]-2*sz[v];
            dfs2(v,node,g,dp);
        }
    }
}
void solve()
{
    int n;cin>>n;
    vector<int>w(n+1);
    for(int i=1;i<=n;i++)cin>>w[i];
    vector<vector<int>>g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>dp(n+1,0);
    dfs(1,0,0,g,w,dp);
    dfs2(1,0,g,dp);
    dp.erase(dp.begin());
    cout<<*max_element(dp.begin(),dp.end())<<" "<<*min_element(dp.begin(),dp.end())<<endl;
}

signed main()
{ 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}