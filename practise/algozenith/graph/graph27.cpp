#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,q,cc;
vector<int>par,rnk;
int find(int node){
    if(par[node]==node)return node;
    return par[node]=find(par[node]);
}
void merge(int u, int v){
    int p1=find(u);
    int p2=find(v);
    if(p1!=p2)cc--;
    if(rnk[p1]>rnk[p2]){
        rnk[p1]+=rnk[p2];
        par[p2]=p1;
    }else{
        rnk[p2]+=rnk[p1];
        par[p1]=p2;
    }
}
void solve()
{
    cin>>n>>m>>q;
    cc=n;
    vector<pair<int,int>>edge(m+1);
    par.clear();
    par.resize(n+1);
    for(int i=1;i<=n;i++)par[i]=i;
    rnk.clear();
    rnk.resize(n+1,1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[i]={u,v};
    }
    set<int>st;
    vector<pair<int,int>>query;
    for(int i=0;i<q;i++){
        int x;cin>>x;
        int y;
        if(x==1){
            cin>>y;
            st.insert(y);
        }
        query.push_back({x,y});
    }
    reverse(query.begin(),query.end());
    for(int i=1;i<=m;i++){
        int u=edge[i].first;
        int v=edge[i].second;
        if(st.count(i)>0)continue;
        merge(u,v);
    }
     
    vector<int>ans;
    for(int i=0;i<query.size();i++){
        int x=query[i].first;
        if(x==1){
            int id=query[i].second;
            int u=edge[id].first;
            int v=edge[id].second;
            merge(u,v);
        }else{
            // cout<<cc<<endl;
            ans.push_back(cc);
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
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