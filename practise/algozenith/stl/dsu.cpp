#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
class DSU{
    vector<int>par;
    vector<int>rank;
    public:
    DSU(int n){
        for(int i=0;i<=n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int node){
        if(node==par[node])return node;
        return par[node]=find(par[node]);
    }
    void unionn(int a, int b){
        a=find(a);
        b=find(b);
        if(rank[a]>rank[b]){
            swap(a,b);
        }
        par[a]=b;
        if(rank[a]==rank[b])rank[b]++;
    }
};
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>edge(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
    }
    int ans=0;
    int ones=-1;
    for(int i=31;i>=0;i--){
        DSU d(n);
        int cnt=0;
        for(auto e:edge){
            int u=e[0],v=e[1],w=e[2];
            int pref=w&(ones<<i);
            int orr=(ans|pref);
            if(orr!=ans)continue;//notsubmask
            if(d.find(u)==d.find(v))continue;
            cnt++;
            d.unionn(u,v);
        }
        if(cnt!=n-1){
            ans^=(1<<i);
        }
        // d.print(n);
    }
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}