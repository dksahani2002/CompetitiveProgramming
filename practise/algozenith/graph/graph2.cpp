#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
int n,m;
int ans;
void dfs(int node,int par,vector<int>&vis){
    vis[node]=1;
    for(auto v:g[node]){
        if(v==par)continue;
        if(vis[v]==0){
            dfs(v,node,vis);
        }else{
            ans=1;
            return;
        }
    }
    vis[node]=2;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=0;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0,vis);
        }
    }
    
    if(ans){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}