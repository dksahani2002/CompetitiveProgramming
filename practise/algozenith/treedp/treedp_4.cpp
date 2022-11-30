#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
vector<vector<pair<int,int>>>g;
// vector<vector<int>>dp;
int dp[100100][2];
void dfs(int node,int par){
    dp[node][0]=dp[node][1]=0;
    vector<int>del;
    int base=0;
    for(auto x:g[node]){ 
        int v=x.first;
        int w=x.second;
        if(v!=par){
            dfs(v,node);
            base+=dp[v][1];
            del.push_back(dp[v][0]-dp[v][1]+w);
        }
    }
    sort(del.rbegin(),del.rend());
    del.insert(del.begin(),0);
    for(int j=0;j<del.size();j++){
        base+=del[j];
        if(j==k){
            dp[node][1]=max(base,dp[node][1]);
            break;
        }
        dp[node][1]=max(dp[node][1],base);
        dp[node][0]=max(dp[node][0],base);
    }
}
void solve()
{
    g.clear();
    int n;cin>>n>>k;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);  
    cout<<dp[1][1]<<endl;
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}