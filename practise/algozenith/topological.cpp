#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
int par[100];
int n;
vector<int>topo;
int vis[100];
int indegree[100];
void dfs(int node , int p){ 
    // vis[node]=1;
    // par[node]=p;
    // for(auto neigh:g[node]){
    //     if(vis[neigh]==0){
    //         dfs(neigh,node);
    //     }else if(neigh!=p){
    //        int cur=node;
    //         while(cur!=neigh){
    //             cout<<cur<<" ";
    //             cur=par[cur];
    //         }
    //         cout<<cur<<endl;
    //     }
    // }
    queue<int>q;
    for(int i=1;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        topo.push_back(x);
        for(auto neigh:g[x]){
            indegree[neigh]--;
            if(indegree[neigh]==0)q.push(neigh);
        }
    }
}
int main(){

     
     cin>>n;
    //  g.clear();
     for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
        // g[v].push_back(u);
         
     }
     memset(vis,0,sizeof(vis));
     memset(par,0,sizeof(par));
    //  par[1]=-1;
    dfs(1,-1);
    for(auto i:topo){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}