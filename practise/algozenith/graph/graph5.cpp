#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,q;
vector<vector<int>>g;
void dfs(int node,vector<int>&vis,int &sz){
    vis[node]=1;
    sz++;
    for(auto v:g[node]){
        if(vis[v]==-1){
           dfs(v,vis,sz);
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
    vector<int>vis(n+1,-1);
    int ans=0;
    vector<int>res;
    int sol=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            int sz=0;
           dfs(i,vis,sz);
           res.push_back(sz);
        }
    }
    
    if(res.size()==1){
        cout<<0<<endl;
    }else{
        for(auto x:res){
            // cout<<x<<endl;
            sol+=x*(n-x);
            n-=x;
        }
        cout<<sol<<endl;
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