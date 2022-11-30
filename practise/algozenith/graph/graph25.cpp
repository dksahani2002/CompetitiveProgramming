#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<pair<int,int>>>g;
void dijkstra(){
    vector<int>dis(n+1,1e18),vis(n+1,0);
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    deque<int>dq;
    dq.push_front(1);
    dis[1]=0;
    while(!dq.empty()){
        auto node=dq.front();dq.pop_front();
        for(auto x:g[node]){
            int v=x.first;
            int w=x.second;
            if(w==0){
                if(dis[v]>dis[node]){
                    dis[v]=dis[node];
                    dq.push_front(v);
                }
            }else{
                 if(dis[v]>w+dis[node]){
                    dis[v]=w+dis[node];
                    dq.push_back(v);
                }
            }
        }
    }
    if(dis[n]==1e18){
        cout<<-1<<endl;
        return;
    }
    cout<<dis[n]<<endl;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    dijkstra();
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