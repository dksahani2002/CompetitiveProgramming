#include <bits/stdc++.h>
using namespace std;
#define int long long
    
int dfs(int node , int target,int weight,vector<vector<pair<int,int>>>&g){
    int ans=0;
    for(auto v:g[node]){
        int  neigh=v.first;
        int w=v.second;
        if(w==weight)ans++;
        if(node==target)return ans;
        dfs(neigh,target,weight,g);
    }
    return ans;
}
vector<int>Solution:: solve(vector<int>A, vector<vector<int>>B, vector<vector<int>>C){
    int n=A.size();
     vector<vector<pair<int,int>>>g(n);
     for(int i=0;i<B.size();i++){
        int u,v,w;
        u=B[i][0];
        v=B[i][1];
        w=A[i];
        g[u-1].push_back({v-1,w});
        g[v-1].push_back({u-1,w});
     }
    vector<int>ans(C.size());
    for(int i=0;i<C.size();i++){
        int u=C[i][0];
        int v=C[i][1];
        int w=C[i][2];
        ans[i]=dfs(u-1,v-1,w,g);
    }
    return ans;
}
void sol()
{
     int n,m;
     cin>>n>>m;
     vector<vector<pair<int,int>>>g(n);
     for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u-1].push_back({v-1,w});
     }
     ans.resize(n);
    int x;cin>>x;
     dfs(0,g,x);
    // return ans;
    for(auto i:ans){
        cout<<i<<" ";

    }
    return ;

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