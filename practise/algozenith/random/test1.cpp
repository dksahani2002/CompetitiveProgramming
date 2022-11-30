#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,r;
vector<vector<int>>g;
vector<int>dis,par;
vector<int>tim;
vector<int>w;
set<int>ch;
void dfs(int node,int pp,int lev){
    dis[node]=dis[pp]+w[node];
    par[node]=pp;
    tim[node]=lev;
    int c=0;
    for(auto v:g[node]){ 
        if(v!=pp){
            dfs(v,node,lev+1);
            c++;
        }
    }
    if(c==0){
        ch.insert(node);
    }
}
void dfs2(int node,int par,int val){
    dis[node]-=val;
    for(auto v:g[node]){
       if(v!=par){
        dfs(v,node,val);
       } 
    }
}
void solve()
{
    g.clear();
    ch.clear();
    int n;cin>>n>>r;
    w.resize(n+1);
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>w[i];
    dis.assign(n+1,0);
    par.assign(n+1,0);
    tim.assign(n+1,0);
    dfs(1,0,0); 
    int t=tim[r];
    int x=0;
    int node=r;
    int req;
    while(par[node]!=0){
        if(x<t){
            dis[r]-=w[node];
        }
        if(x==t){
            dis[r]-=w[node]/2;
            req=node;
            break;
        }
        t--;
        x++;
        node=par[node];
    }
    int ans=dis[r];
    dfs2(req,par[req],w[req]/2);
    ch.erase(r);
    for(auto i:ch){
        ans=max(ans,dis[i]);
    }
    cout<<ans<<endl;
     
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}