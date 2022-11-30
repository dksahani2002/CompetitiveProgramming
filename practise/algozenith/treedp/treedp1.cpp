#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int indp[100001],outdp[100001],sz[100001];
vector<vector<int>>g;
void indfs(int node,int par){
    indp[node]=0;
    for(auto v:g[node]){
        if(v!=par){
        indfs(v,node);
        indp[node]=max(indp[node],1+indp[v]);
        }
    }  
}
void outdfs(int node,int par,int val){
     outdp[node]=val;

     //standard way to calculate max1 and max2
     int max1=-1,max2=-1;
     for(auto x:g[node]){
        if(x!=par){
            if(indp[x]>max1){
                max2=max1;
                max1=indp[x];
            }else if(indp[x]>max2){
                max2=indp[x];
            }
        }
     }
     //
    for(auto v:g[node]){
        if(v!=par){
          if(indp[v]==max1)outdfs(v,node,max(max2+2,outdp[node]+1));
          else outdfs(v,node,max(max1+2,outdp[node]+1));
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
    outdfs(1,0,0);
    for(int i=1;i<=n;i++)cout<<max(indp[i],outdp[i])<<" ";
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