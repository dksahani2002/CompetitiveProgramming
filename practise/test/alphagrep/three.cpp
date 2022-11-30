#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int n;
vector<int>par,rnk;
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
set<int>s;
void init(){
    par.resize(n+1,-1);
    rnk.resize(n+1,1);
}
int find(int u){
    if(par[u]==-1)return u;
    return par[u]=find(par[u]);
}
void merge(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v)return;
    cout<<"hhh"<<endl;
    rnk[u]+=rnk[v];
    par[v]=u;
    s.insert(rnk[u]);
}
void solve()
{
    n=5;
    vector<int>a={1,1,2,2};
    vector<int>b={2,5,3,4};
    int q;q=1;
    vector<vector<int>>fq(q,vector<int>(2));
    set<pair<int,int>>st;
    for(int i=0;i<q;i++){
        fq[i][0]=1;
        fq[i][1]=2;
        st.insert({fq[i][0],fq[i][1]});
    }
    for(int i=0;i<n-2;i++){
        if(st.count({a[i],b[i]}))continue;
        cout<<"hio"<<endl;
        merge(a[i],b[i]);
        cout<<"hi"<<endl;
    }
    for(auto x:s){
        cout<<x<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}