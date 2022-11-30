#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<pair<int,int>>>g;
map<pair<int,int>>mapper;
 int in[100100],ou[100100];
 void dfs(int node,int par){
    // in[node]=0;
    int cnt=0;
    for(auto v:g[node]){
        int neigh=v.first;
        int w=v.second;
        if(neigh!=par){
            dfs(neigh,node);
            cnt++;
            in[node]=min(in[node],w+ind[neigh]);
        }
    }
    if(cnt==0)in[node]=0;
 }
 void dfs(int node,int par){
    int mx1=1e9,mx2=1e9;
    for(auto v:g[node]){
         int neigh=v.first;
         int w=v.second;
         if(in[neigh]+w<mx1){
            mx2=mx1;mx1=in[neigh]+w;
         }else if(in[neigh]+w<mx2)mx2=in[neigh]+w;
    }
    for(auto v:g[node]){
        int neigh=v.first;
        int w=v.second;
        if(neigh!=par){
            int use=mx1;
            if(in[neigh]+w==mx1)use=mx2;
            ou[neigh]=mapper[{neigh,node}]+min(ou[node],use);
            dfs(neigh,node);
        }
    }
 }
void solve()
{
     int n;cin>>n;
     g.clear();
     g.resize(n+1);
     for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,0});
        mapper[{u,v}]=w;
        mapper[{v,u}]=0;
     }
     for(int i=1;i<=n;i++){
        in[i]=1e9;
        ou[i]=1e9;
     }
    dfs(1,0);

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