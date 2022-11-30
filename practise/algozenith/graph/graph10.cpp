#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
int n,m;
int ans;
bool dfs(int node,vector<int>&vis){
    vis[node]=1;
    for(auto v:g[node]){
        if(vis[v]==-1 && dfs(v,vis)){
            return true;
        }else if(vis[v]==1){
            return true;
        }
    }
    vis[node]=2;
    return false;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    ans=0;
    vector<int>vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            if(dfs(i,vis)){
                cout<<"Yes\n";
                return;
            }
        }
    }
     
    cout<<"No\n";
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