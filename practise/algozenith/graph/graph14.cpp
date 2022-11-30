#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>par,rnk;
int ans,cnt;
int n,m;
int find(int u){
    if(par[u]==-1)return u;
    return par[u]=find(par[u]);
}
void merge(int u, int v, int w){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2)return;
    ans+=w;
    cnt++;
    if(rnk[p1]>=rnk[p2]){
        par[p2]=p1;
        rnk[p1]+=rnk[p2];
    }else{
         par[p1]=p2;
        rnk[p2]+=rnk[p1];
    }
}
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void solve()
{
    vector<vector<int>>edge;
    cin>>n>>m;
    par.clear();
    rnk.clear();
    par.resize(n+1,-1);
    rnk.resize(n+1,0);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    ans=0,cnt=0;
    sort(edge.begin(),edge.end(),cmp);
    for(auto e:edge){
        int u=e[0],v=e[1],w=e[2];
        merge(u,v,w);
    }
    if(cnt!=n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
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