#include<bits/stdc++.h>
using namespace std;
vector<int>top;
vector<vector<int>>adj(100005);
vector<int>vis(100005);
void dfs(int u){
    for(auto i:adj[u]){
        if(!vis[i]){
            vis=1;
            dfs(i);
        }
    }
    top.push_back(u);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
    reverse(top.begin(),top.end());
    vector<int>pos(n);
    for(int i=0;i<n;i++){
        pos[top[i]]=i;
    }
    int f=0;
    for(auto i:edges){
        if(pos[i.second]<=pos[i.first]){
            f=1;
            break;
        }
    }
    if(f)cout<<"No\n";
    else cout<<"Yes\n";
}