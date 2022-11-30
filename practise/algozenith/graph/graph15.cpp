#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<pair<int,int>>>g;
void dfs(int node,vector<int>&dis,vector<int>&vis){
  
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,node});
    while(!q.empty()){
        auto p=q.top();q.pop();
        int nod=p.second;
        int d=p.first;
        if(vis[nod])continue;
        vis[nod]=1;

        for(auto x:g[nod]){
            int v=x.first;
            int w=x.second;
            if(dis[v]>w+d){
                dis[v]=w+d;
                q.push({dis[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int>dis(n+1,1e18),vis(n+1,0);
    dis[1]=0;
    dfs(1,dis,vis);
    for(int j=1;j<=n;j++){
        cout<<dis[j]<<" ";
    }
    cout<<endl;
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