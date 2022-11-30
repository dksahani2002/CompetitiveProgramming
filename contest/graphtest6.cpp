#include <bits/stdc++.h>
using namespace std;
#define int long long
void  dfs(int node,vector<int>&vis,int &cnt,vector<vector<int>>&g){
    cnt++;
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,vis,cnt,g);
        }
    }
}
void solve()
{
    int n,r,cc,cr;
    cin>>n>>r>>cc>>cr;
    vector<vector<int>>g(n+1);
    for(int i=0;i<r;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>vis(n+1,0),sz;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int cnt=0;
            dfs(i,vis,cnt,g);
            sz.push_back(cnt);
        }
    }
    int ans=cc*n;
    int res=0;
    for(int i=0;i<sz.size();i++){
        int count=sz[i];
        // res+=(count-1)*cr+cc;
        int x=1e18;
        for(int j=1;j<=count;j++){
            x=min(x,j*cc+(count-j)*cr);
        }
        res+=x;
    }
    cout<<min(res,ans)<<endl;
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