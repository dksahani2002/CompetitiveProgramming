#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e18+7;
int n,m;
vector<vector<pair<int,int>>>g;
void bellmon_ford(){
    vector<int>dis(n+1,1e18);
    dis[1]=0;
    for(int i=1;i<=n;i++){
        for(auto x:g[i]){
            int neigh=x.first;
            int w=x.second;
            if(dis[neigh]>dis[i]+w){
                dis[neigh]=dis[i]+w;
            }
        }
    }
    int ans=-1e18;
    for(int i=1;i<=n;i++){
        for(auto x:g[i]){
            int neigh=x.first;
            int w=x.second;
            if(dis[neigh]>dis[i]+w){
                cout<<-1<<endl;
                return ;
            }
        }
    }
    
    cout<<-dis[n]<<endl;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,-w});
    }
    bellmon_ford();
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