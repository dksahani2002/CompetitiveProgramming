#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e18+7;
int n,m,q;
// vector<vector<pair<int,int>>>g;
// void dijkstra(int node, int start, vector<int>&vis,vector<vector<int>>&dis){
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     pq.push({0,node});
//     while(!pq.empty()){
//         auto p=pq.top();pq.pop();
//         int nod=p.second;
//         int d=p.first;
//         if(vis[nod])continue;
//         vis[nod]=1;
//         for(auto x:g[node]){
//             int v=x.first;
//             int w=x.second;
//             if(dis[start][v]>w+d ){
//                 dis[start][v]=w+d;
//                 pq.push({w+d,v});
//             }
//         }
//     }
// }
void solve()
{
    cin>>n>>m>>q;
    // g.clear();
    // g.resize(n+1);
    vector<vector<int>>dis(n+1,vector<int>(n+1,1e18));
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        // g[u].push_back({v,w});
        // g[v].push_back({u,w});
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }
    // for(int i=1;i<=n;i++){
    //     dis[i][i]=0;
    //     vector<int>vis(n+1,0);
    //     dijkstra(i,i,vis,dis);
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dis[i][j]=0;
                    continue;
                }
                 dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(dis[u][v]==1e18){
            cout<<-1<<endl;
        }else{
            cout<<dis[u][v]<<endl;
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