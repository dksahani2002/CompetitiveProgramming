#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ans=true;
int target;
vector<int>par;
void dfs(int node,int pp,vector<vector<int>>&g,vector<int>&lev,int l){
    lev[node]=l;
    par[node]=pp;
    for(auto v:g[node]){
        if(v!=pp)dfs(v,node,g,lev,l+1);
    }
}
void dfs2(int node,int pp,vector<vector<int>>&g,vector<int>&lev,int l){
    lev[node]=l;
    if(g[node].size()==1 && lev[node]<=target){
        ans=true;
        return;
    }
    for(auto v:g[node]){
        if(v!=pp && lev[v]>1+lev[node]){
            dfs2(v,node,g,lev,l+1);
        }
    }
}
void solve()
{
    int n;cin>>n;
    par.resize(n+1);
    vector<vector<int>>g(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>lev(n+1,0);
    dfs(1,0,g,lev,0);//df1 to find diameter
    int node=0;
    for(int i=1;i<=n;i++){
        if(lev[i]>lev[node]){
            node=i;
        }
    }
    dfs(node,0,g,lev,0);//df2 to find diameter
    // cout<<max_lev<<endl;
     node=1;
    for(int i=1;i<=n;i++){
        if(lev[i]>lev[node]){
            node=i;
        }
    }
    target=lev[node]/2-1;
    if(lev[node]&1){
        int c1=node,c2=node;
        for(int i=0;i<lev[node]/2+1;i++){
            c1=par[c1];
            if(i==lev[node]/2)continue;
            c2=par[c2];
        }
        ans=false;
        dfs2(c1,c2,g,lev,0);
        dfs2(c2,c1,g,lev,0);
        if(ans){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }else{
        int c=node;
        for(int i=0;i<lev[node]/2;i++){
             c=par[c];
        }
        ans=false;

        dfs2(c,0,g,lev,0);
        if(ans){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
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