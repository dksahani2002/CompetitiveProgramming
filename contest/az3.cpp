#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
void dfs(int node,vector<int>&dis,vector<vector<pair<int,int>>>&g ){
    for(auto x:g[node]){
        int neigh=x.first;
        int w=x.second;
        if(dis[neigh]>dis[node]+w){
            dis[neigh]=dis[node]+w;
            dfs(neigh,dis,g);
        }
    }
}
int  best_hospital(vector<vector<int>>edge,vector<int>xyz){
    vector<vector<pair<int,int>>>g(n+1);
    for(auto e:edge){
        g[e[0]].push_back({e[1],e[2]});
        g[e[1]].push_back({e[0],e[2]});
    }
    vector<int>dis1(n+1,1e9);
    vector<int>dis2(n+1,1e9);
    vector<int>dis3(n+1,1e9);
    dis1[xyz[0]]=0;
    dfs(xyz[0],dis1,g);
     dis2[xyz[1]]=0;
    dfs(xyz[1],dis2,g);
     dis3[xyz[2]]=0;
    dfs(xyz[2],dis3,g);
    int ans=1e9;
    int index=0;
    for(int i=1;i<=n;i++){
        if(dis1[i]+dis2[i]+dis3[i] <ans){
            ans=dis1[i]+dis2[i]+dis3[i];
            index=i;
        }
    }
    return index;
} 
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        cin>>n;
        vector<vector<int>>edge(n-1);
        vector<int>xyz;
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edge[i]={u,v,w};
        }
        for(int i=0;i<3;i++){
            int x;cin>>x;
            xyz.push_back(x);
        }
       cout<< best_hospital(edge,xyz)<<endl;
    }
}