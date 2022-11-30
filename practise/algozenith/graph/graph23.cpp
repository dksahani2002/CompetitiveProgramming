#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,a,b;
vector<vector<pair<int,int>>>g;
void dijkstra(int src){
    src--;
    vector<int>dis(2*n+10,1e18),vis(2*n+10,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src]=0;
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
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
void solve()
{
    cin>>n>>a>>b;
    g.clear();
    g.resize(2*n+10);
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        mp[val].push_back(i);
    }
     
    for(int i=0;i<n-1;i++){
        g[i].push_back({i+1,b});
        g[i+1].push_back({i,b});
    }
    int supnode=n;
    for(auto x:mp){
        for(auto v:x.second){
            g[v].push_back({supnode,0});
            g[supnode].push_back({v,a});
        }
        supnode++;
    }
    int src;
    cin>>src;
    dijkstra(src);
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