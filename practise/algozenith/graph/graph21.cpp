#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<pair<int,int>>>g;
void dijkstra(int node, vector<int>&dis){
        dis[node]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        vector<int>vis(n+1,0),tot_flight(n+1,0),min_flight(n+1,0),max_flight(n+1,0);
        tot_flight[node]=1;
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            int nod=p.second;
            int d=p.first;
            if(vis[nod])continue;
            vis[nod]=1;
            for(auto x:g[nod]){
                int v=x.first;
                int w=x.second;
                if(dis[v]>w+d){
                    dis[v]=w+d;
                    tot_flight[v]=tot_flight[nod];
                    min_flight[v]=min_flight[nod]+1;
                    max_flight[v]=max_flight[nod]+1;
                    pq.push({w+d,v});
                }else if(dis[v]==w+d){
                    tot_flight[v]=(tot_flight[v]+tot_flight[nod])%mod;
                    min_flight[v]=min(min_flight[v],min_flight[nod]+1);
                    max_flight[v]=max(max_flight[v],max_flight[nod]+1);
                    
                }
            }
        }
        if(dis[n]==1e18){
            cout<<-1<<endl;
            return;
        }
        cout<<dis[n]<<" "<<tot_flight[n]<<" "<<min_flight[n]<<" "<<max_flight[n]<<endl;
}
int cnt,mini,maxi;
void dfs(int node,int leftcost,int count,vector<int>&dis){
    if(node==n){
        if(leftcost==0){
            cnt=(cnt+1)%mod;
            mini=min(count,mini);
            maxi=max(count,maxi);
        }
        return;
    }
    for(auto x:g[node]){
        int v=x.first;
        int w=x.second;
        if(dis[v]==dis[node]+w){
            dfs(v,leftcost-w,count+1,dis);
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
    vector<int>dis(n+1,1e18);
    dijkstra(1,dis);
    // cout<<dis[n]<<endl;
    // if(dis[n]==1e18){
    //         cout<<-1<<endl;
    //         return;
    // }
    // cnt=0,mini=1e9,maxi=0;
    // dfs(1,dis[n],0,dis);
    // cout<<dis[n]<<" "<<cnt<<" "<<mini<<" "<<maxi<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
