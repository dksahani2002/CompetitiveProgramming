#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int indp[100001],outdp[100001],sz[100001];
vector<vector<int>>g;

void indfs(int node,int par){
    indp[node]=0;
    sz[node]=1;
    for(auto v:g[node]){
        if(v!=par){
        indfs(v,node);
        sz[node]+=sz[v];
        indp[node]+=indp[v]+sz[v];
        }
    }
}
void outdfs(int node,int par){
    if(node==1)outdp[node]=0;
    else outdp[node]=outdp[par]+indp[par]-(sz[node]+indp[node])+(n-sz[node]);
    for(auto v:g[node]){
        if(v!=par){
        outdfs(v,node);
        }
    }
}
void solve()
{
    cin>>n;
    // vector<vector<int>>g(n+1);
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0);
    for(int i=1;i<=n;i++)cout<<indp[i]+outdp[i]<<" ";
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