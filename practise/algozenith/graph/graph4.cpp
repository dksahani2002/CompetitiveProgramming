#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,q;
vector<vector<int>>g;
void dfs(int node,int id,vector<int>&vis,int &sz){
    vis[node]=id;
    sz++;
    for(auto v:g[node]){
        if(vis[v]==-1){
           dfs(v,id,vis,sz);
        }
    }
}
void solve()
{
    cin>>n>>m>>q;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>vis(n+1,-1);
    map<int,int>mp;
    int id=1;
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            int sz=0;
           dfs(i,id,vis,sz);
           mp[id]=sz;
           id++;
        }
    }
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int node;cin>>node;
            cout<<mp[vis[node]]<<endl;
        }else{
            int u,v;cin>>u>>v;
            if(vis[u]==vis[v]){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
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