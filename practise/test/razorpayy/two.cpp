#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
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


vector<int> city_population(int N, vector<int>population, vector<vector<int>>road,int Q, vector<vector<int>>cities,vector<int>out_n){

    int n;n=N;
    val.clear();
    val.resize(n+1);
    for(int i=0;i<n;i++)val[i+1]=population[i];
    g.clear();
    g.resize(n+1);
    for(int i=0;i<n-1
    ;i++){
        int u,v;
        u=road[i][0];
        v=road[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    int q;q=Q;
    int i=0;
    vector<int>res;
    while(q--){
        int u,v,w;
        u=cities[i][0];
        v=cities[i][1];
        w=cities[i][2];
        int lca=find_lca(u,v,w);
        int ans=find(u,w,lca)+find(v,w,lca);
        if(u!=lca && v!=lca)ans+=(val[lca]<=w);
        // cout<<ans<<endl;
        res.push_back(ans);
        i++;
    }
    return res;
}
void solve()
{
    int n;cin>>n;
    vector<int>popu(n);
    for(int i=0;i<n;i++)cin>>popu[i];
     vector<vector<int>>road(n-1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        road[i].push_back(u);
        road[i].push_back(v);
    }
     
    int q;cin>>q;
    int i=0;
     vector<vector<int>>cities(q);

    while(i<q){
        i++;
        int u,v,w;cin>>u>>v>>w;
         cities[i].push_back(u);
         cities[i].push_back(v);
         cities[i].push_back(w);
    }
    vector<int>ans=city_population(n,popu,road,q,cities,popu);
    for(auto e:ans)cout<<e<<" ";
    cout<<endl;
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