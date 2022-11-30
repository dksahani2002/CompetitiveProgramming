#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
void dfs(int node,vector<int>&dis,int des,vector<vector<pair<int,int>>>&g,int sum,int k){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    // queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{k,node}});
    while(!pq.empty()){
        // int sz=pq.size();
        // while(sz--){
            auto p=pq.top();pq.pop();
            int cost=p.first;
            int nod=p.second.second;
            int left=p.second.first;
            if(nod==des){
              if(left>=0)  ans=min(ans,cost);
            }
            // if(k<)
            for(auto x:g[nod]){
                int v=x.first;
                int w=x.second;
                if(left>0 && dis[v]>cost+w){
                    dis[v]=cost+w;
                    pq.push({dis[v],{left-1,v}});
                }
            }
            
        // }
    }
}
void solve()
{
    int n,m,des;cin>>n;
    cin>>des;
    cin>>m;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int k;cin>>k;
    ans=1e18;
    vector<int>vis(n+1,1e18);
    vis[1]=0;
    dfs(1,vis,des,g,0,k);
    if(ans==1e18){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}