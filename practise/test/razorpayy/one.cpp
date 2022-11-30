#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;

class DSU{
    vector<int>par;
    vector<int>rank;
    public:
    DSU(int n){
        for(int i=0;i<=n;i++){
            par.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int node){
        if(node==par[node])return node;
        return par[node]=find(par[node]);
    }
    int unionn(int a, int b){
        a=find(a),b=find(b);
        if(rank[a]>rank[b])swap(a,b);
        int val=rank[a]*rank[b];
        par[a]=b,rank[b]+=rank[a];
        return val;
    }
     
};
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]>b[2];
}
void solve()
{
    int n;cin>>n;
    DSU ds(n);
    // ds.print();
    vector<vector<int>>edge(n-1,vector<int>(3));
    for(int i=0;i<n-1;i++){
        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
    }
    sort(edge.begin(),edge.end(),cmp);
    int ans=0;

    for(auto e:edge){
        int w=e[2],u=e[0],v=e[1];
        ans+=w*ds.unionn(u,v);
    }
    cout<<ans<<endl;
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