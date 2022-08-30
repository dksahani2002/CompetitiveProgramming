#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
int par[100];
int vis[100];
void dfs(int node , int p){ 
    vis[node]=1;
    par[node]=p;
    for(auto neigh:g[node]){
        if(vis[neigh]==0){
            dfs(neigh,node);
        }else if(neigh!=p){
           int cur=node;
            while(cur!=neigh){
                cout<<cur<<" ";
                cur=par[cur];
            }
            cout<<cur<<endl;
        }
    }
}
int main(){

     int n;
     cin>>n;
    //  g.clear();
     for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        // g[v].push_back(u);
         
     }
     memset(vis,0,sizeof(vis));
     memset(par,0,sizeof(par));
    //  par[1]=-1;
    dfs(1,-1);
    return 0;
}