#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100100];
vector<int>vis(100100,0),subtreeSz(100100,0),par(100100,-1),vis2(100100,0);
vector<int>depth(100100,0);
int count ;
void  bfs(int node  ,int parent,int dep){
    vis[node]=1;
    par[node]=parent;
    depth[node]=dep;
    subtreeSz[node]=1;
    for(auto neigh:g[node]){
        if(neigh !=parent ){
            bfs(neigh,node,dep+1);
            subtreeSz[node]+=subtreeSz[neigh];
        }
    }
}
void bfs2(int node , int p ,int &count){ 
    int m1=-1,m2=1e9;
    int visnod=-1,cntnod=-2; 
     for(auto neigh:g[node]){
        if(neigh!=p){
            if( depth[neigh]>m1){
                m1=depth[neigh];
                visnod=neigh;
            }
            if(depth[neigh]<m2){
                m2=depth[neigh];
                cntnod=neigh;
            }
            
        }
        
     }
     if(visnod==-1 && cntnod==-2){
        return;
     }
    if(m1<=m2){
        count+=subtreeSz[visnod]-1;
        bfs2(cntnod,node,count);
    }else{
         count+=subtreeSz[cntnod]-1;
        bfs2(visnod,node,count);
    }
}
void solve()
{   
    int n;cin>>n;  
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v; 
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    vis[1]=1;
    bfs(1 ,-1,0); 
    int count=0; 
    bfs2(1,-1,count);
    cout<<count<<endl;
     
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