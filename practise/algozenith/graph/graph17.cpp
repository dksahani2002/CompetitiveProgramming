#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<pair<int,int>>>g;
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    vector<vector<int>>edge(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edge[i]={u,v,w};
    }
    int a;cin>>a;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(n+1,0),dis(n+1,1e9);
    pq.push({0,a});
    dis[a]=0;
    while(!pq.empty()){
        auto p=pq.top();pq.pop();
        int node=p.second;
        int d=p.first;
        if(vis[node])continue;
        vis[node]=1;
        for(auto x:g[node]){
            int v=x.first;
            int w=x.second;
            if(dis[v]>w+d){
                dis[v]=w+d;
                pq.push({w+d,v});
            }
        }
    }
    int curMax=0;
    for(int i=1;i<=n;i++)curMax=max(curMax,dis[i]);
    curMax*=10;
    for(auto e:edge){
        curMax=max(5*(e[2]+dis[e[0]]+dis[e[1]]),curMax);
    }
    cout<<curMax<<endl;

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