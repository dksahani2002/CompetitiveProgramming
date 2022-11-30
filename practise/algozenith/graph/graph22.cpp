#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
int res;
void dfs(int node,vector<int>&dis){
    // par[node]=pp;
    // vis[node]=1;
    // for(auto v:g[node]){
    //     if(v==pp)continue;
    //     if(vis[v]==-1){
    //         dfs(v,node,vis,par);
    //     }else if(vis[v]==1){
    //         ans=0;
    //         int neigh=node;
    //         int temp=1;
    //         while(neigh!=v){
    //             temp++;
    //             neigh=par[neigh];
    //         }
    //         res=min(res,temp);
    //     }
    // }
    // vis[node]=2;
    queue<int>q;
    q.push(node);
    dis[node]=0;
    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto v:g[node]){
            if(dis[v]==1e9){
                dis[v]=dis[node]+1;
                q.push(v);
            }else if(dis[v]>=dis[node]){
                res=min(res,dis[v]+dis[node]+1);
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    map<pair<int,int>,int>mp;
    int check=0;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{min(u,v),max(u,v)}]++;
        if(mp[{min(u,v),max(u,v)}]>1)check=1;
    }
    if(check){
        cout<<2<<endl;
        return;
    }
    res=1e9;
    for(int i=1;i<=n;i++){
        vector<int>dis(n+1,1e9);
        
        dfs(i,dis);
        
    }
    if(res==1e9){
        cout<<-1<<endl;
        return;
    }

    cout<<res<<endl;
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