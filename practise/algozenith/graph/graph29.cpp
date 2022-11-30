#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>par,rnk;
int n;
int ans;
int find(int nod){
    if(par[nod]==-1)return nod;
    return par[nod]=find(par[nod]);
}
void merge(int u,int v, int w){
    int p1=find(u);
    int p2=find(v);
    if(rnk[p1]>rnk[p2]){
        ans+=w*rnk[p1]*rnk[p2];
        rnk[p1]+=rnk[p2];
        par[p2]=p1;
    }else{
        ans+=w*rnk[p1]*rnk[p2];
        rnk[p2]+=rnk[p1];
        par[p1]=p2;
    }
}
bool cmp(vector<int>&a, vector<int>&b){
    return a[2]>b[2];
}
void solve()
{
    cin>>n;
    par.clear();
    par.resize(n+1,-1);
    rnk.clear();
    rnk.resize(n+1,1);
    vector<vector<int>>edge(n-1);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
    }
    ans=0;
    sort(edge.begin(),edge.end(),cmp);
    for(auto e:edge){
        merge(e[0],e[1],e[2]);
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