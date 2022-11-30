#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
int u,v,c;
vector<vector<pair<int,int>>>g;
vector<int>petrol;
int rec(){
    //nahi jaye
    int dp[n+1][c+1];
    int vis[n+1][c+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            dp[i][j]=1e9;
            vis[i][j]=0;
        }
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{u,0}});
    dp[u][0]=0;
    while(!pq.empty()){
        auto p=pq.top();pq.pop();
        int node=p.second.first;
        int fuel=p.second.second;
        int dis=p.first;
        if(vis[node][fuel])continue;
        vis[node][fuel]=1;
        if(fuel<c && dis+petrol[node]<dp[node][fuel+1]){
            dp[node][fuel+1]=dis+petrol[node];
            pq.push({dis+petrol[node],{node,fuel+1}});
        }
        for(auto v:g[node]){
            if(fuel>=v.second && dp[v.first][fuel-v.second]>dis){
                dp[v.first][fuel-v.second]=dis;
                pq.push({dis,{v.first,fuel-v.second}});
            }
        }
    }
    int mini=1e9;
    for(int i=0;i<=c;i++){
        mini=min(mini,dp[v][i]);
    }
    return mini;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
     petrol.clear();
    petrol.resize(n+1);
    for(int i=0;i<m;i++){
        int w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        cin>>petrol[i];
    }
    cin>>u>>v>>c;
    cout<<rec()<<endl;
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