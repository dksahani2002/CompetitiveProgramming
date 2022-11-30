#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dp[10001][20];
vector<vector<int>>g;
int indfs(int node,int par,int gc){
    int ans=0;
    if(dp[node][gc]!=-1)return dp[node][gc];
     for(int i=1;i<=20;i++){
        int child=0;
        int temp=1;
        for(auto v:g[node]){
            if(v!=par){
                temp*=indfs(v,node,__gcd(gc,i));
                child++;
            }
        } 
        if(child==0){
            if(__gcd(gc,i)==1)ans++;
        }else{
            ans+=temp;
        }
     }
    return ans;
}
void solve()
{
    cin>>n;
    // vector<vector<int>>g(n+1);
    memset(dp,-1,sizeof(dp));
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   int ans= indfs(1,0,0);
    cout<<ans<<" ";
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