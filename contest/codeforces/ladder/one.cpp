#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<pair<int,int>>>g;
set<int>st;
int des;
void dfs(int node, int par, int x){
    st.insert(x);
    for(auto it:g[node]){
        int neigh=it.first;
        int w=it.second;
        if(neigh!=par && neigh!=des){
            dfs(neigh,node,x^w);
        }
    }
}
bool dfs2(int node, int par, int x){
    
    for(auto it:g[node]){
        int neigh=it.first;
        int w=it.second;
        if(neigh!=par){
            if(dfs2(neigh,node,x^w) || st.count(x^w))return 1;
        }
    }
    return false;
}
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    a--;b--;
    des=b;
    g.clear();
    g.resize(n);
    st.clear();
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(a,-1,0);
    if(dfs2(b,-1,0)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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