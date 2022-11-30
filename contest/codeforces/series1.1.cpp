#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<pair<int,int>>>v(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        v[u].push_back({v,w});
        v[v].push_back({u,w});
    }
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}