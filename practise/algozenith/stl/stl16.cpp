#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int minBatterycapacity(int n, int m, vector<vector<int>>edge){
    vector<vector<pair<int,int>>>g(n);
    for(auto e:edge){
        int u=e[0];
        int v=e[1];
        int w=e[2];
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(n,1e9);
    dis[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto p=pq.top();pq.pop();
        int d=p.first;
        int node=p.second;
        for(auto x:g[node]){
            int v=x.first;
            int w=x.second;
            if(dis[v]>w+d){
                dis[v]=w+d;
                pq.push({w+d,v});
            }
        }
    }
    return dis[n-1];
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>edge(m,vector<int>(3));
    for(int i=0;i<m;i++){
        // int u,v,w;
        // cin>>u>>v>>w;
        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
    }
    cout<<minBatterycapacity(n,m,edge)<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}