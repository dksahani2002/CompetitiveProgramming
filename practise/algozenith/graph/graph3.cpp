#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
int ans;
void dfs(int node, int par, vector<int>&col,int cl){
    col[node]=cl;
    for(auto v:g[node]){
        if(v==par)continue;
        if(col[v]==-1){
            dfs(v,node,col,1-cl);
        }else if(col[v]==cl){
            ans=1;
            return;
        }
    }

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
    vector<int>col(n+1,-1);
    ans=0;
    dfs(1,0,col,0);
    if(ans){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
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