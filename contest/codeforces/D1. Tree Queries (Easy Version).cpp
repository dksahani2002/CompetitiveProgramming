#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
 
vector<int>g[2001];
int vis[2001];
int ch[2001];
void bfs(int node){
    vis[node]=1;
    for(auto neigh:g[node]){
        if(!vis[neigh]){
            bfs(neigh);
            ch[node]++;
        }
        
    }
}
void solve()
{
    
    cin>>n;
     
    for(int i=0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         g[u].push_back(v);
         g[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    memset(ch,0,sizeof(ch));
    bfs(1);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,ch[i]);
    } 
    cout<<ans<<endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}