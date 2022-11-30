#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<pair<int,int>>>g;

int rec(int node,int par,bool ty){
    int ans=0;
    for(auto x:g[node]){
        int neigh=x.first;
        int w=x.second;
        if(neigh==par)continue;
        if(ty){
            int temp=max(w+rec(neigh,node,!ty),rec(neigh,node,ty));
            ans=max(ans,temp);
        }else{
            ans+=rec(neigh,node,!ty);
        }
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout<<rec(1,-1,1)<<endl;
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