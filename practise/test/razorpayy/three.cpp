#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
int n;
vector<int>val;
int par[1001][21];
int parent[1001];
int level[100100];
void dfs(int node,int pp,int lev){
    par[node][0]=pp;
    parent[node]=pp;
    level[node]=lev;
    for(int i=1;i<21;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
    for(auto v:g[node]){
        if(v!=pp){
            dfs(v,node,lev+1);
        }
    }
}
int find_lca(int u, int v, int w){
    if(level[v]<level[u])swap(u,v);
    int dif=level[v]-level[u];
    for(int i=0;i<=20;i++){
        if(dif&(1<<i)){
            v=par[v][i];
        }
    }
    if(v==u)return v;
    for(int i=0;i<=20;i++){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int find(int u,int w, int lca){
    int ans=(val[u]<=w);
    if(u==lca)return ans;
    while(parent[u]!=lca){
        u=parent[u];
        if(val[u]<=w)ans++;
    }
    return ans;
}
void bfs(int node, ordered_set<int>&st){
     queue<int>q;
     q.push(node);
     vector<int>vis(n+1,0);
     while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto nod=q.front();q.pop();
            vis[node]=1;
            st[node].insert(val[node]);
            for(auto v: g[node]){
                if(vis[v])continue;
                st[v]=st[node];
                q.push(v);
            }
        }
     }
}
void solve()
{
   cin>>n;
    val.clear();
    val.resize(n+1);
    for(int i=1;i<=n;i++)cin>>val[i];
    g.clear();
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    bfs(1,st);
    int q;cin>>q;
    while(q--){
        int u,v,w;cin>>u>>v>>w;
        int lca=find_lca(u,v,w);
        int ans=find(u,w,lca)+find(v,w,lca);
        if(u!=lca && v!=lca)ans+=(val[lca]<=w);
        // int ans=st[u].upper_bound(w)-st[u].begin();
        // ans+=st[v].upper_bound(w)-st[v].begin();
        // ans-=2*(st[lca].upper_bound(w)-st[lca].begin());
        cout<<ans<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}