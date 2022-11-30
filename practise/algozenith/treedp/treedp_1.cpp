#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int,int>>>g;
// int indp[100001];
vector<int>indp;
void dfs(int node,int par){
    indp[node]=0;
    for(auto v:g[node]){
        int neigh=v.first;
        int w=v.second;
        if(neigh!=par){
            dfs(neigh,node);
            indp[node]+=w+indp[neigh];
        }
    }
}
void dfs2(int node,int par){
    for(auto v:g[node]){
        int neigh=v.first;
        int w=v.second;
        if(neigh!=par){
            if(w==0){
                indp[neigh]=indp[node]+1;
            }else{
                indp[neigh]=indp[node]-1;

            }
            dfs2(neigh,node);
        }
    }
}
void solve()
{
    int n;cin>>n;
    g.resize(n+1);
    indp.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    for(int i=0;i<=n;i++)indp[i]=0;
    dfs(1,0);
    dfs2(1,0);
    // for(int i=1;i<=n;i++)cout<<indp[i]<<" ";

    int x=*min_element(indp.begin()+1,indp.end());
    cout<<x<<endl;
    for(int i=1;i<=n;i++){
        if(indp[i]==x)cout<<i<<" ";
    }
    cout<<endl;
    g.clear();
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}