#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
void dfs(int node,vector<int>&vis,int des,vector<vector<int>>&g){
    int ch=0;
    vis[node]=1;
    if(g[node].size()==0){
        if(node!=des){
            ans=0;
        }
    }
    for(auto v:g[node]){
        if(vis[v]==0){
            dfs(v,vis,des,g);
            ch++;
        }else if(vis[v]==1){
            ans=0;
            return;
        }
    }
    vis[node]=2; 
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int s,d;cin>>s>>d;
    ans=1;
    vector<int>vis(n+1,0);
    dfs(s,vis,d,g);
    if(ans){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}