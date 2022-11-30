#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<vector<int>>g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>dis(n+1,1e9);
    queue<int>q;
    int ans=1e9;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int node=q.front();q.pop();
            bool flag=true;
            for(auto v:g[node]){
                if(dis[v]>1+dis[node]){
                    dis[v]=1+dis[node];
                    q.push(v);
                }
                flag=false;
            }
            if(flag){
                ans=min(ans,dis[node]);
            }
        }
    }
    for(auto d:dis)cout<<d<<" ";
    cout<<endl;
    cout<<g[5].size()<<endl;
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}