#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
vector<int>col,par;
vector<set<int>>s;
int find(int u){
    if(par[u]==u){
        return u;
    }
    return par[u]=find(par[u]);
}
void merge(int u, int v){
    int p1=find(u);
    int p2=find(v);
    s[p1].insert(s[p2].begin(),s[p2].end());
    par[p2]=p1;

}
void solve()
{
    cin>>n>>m>>q;
    col.resize(n+1);
    par.resize(n+1);
    for(int i=1;i<=n;i++)cin>>col[i];
    for(int i=1;i<=n;i++)par[i]=i;
    vector<vector<int>>g(n+1);
    vector<pair<int,int>>ed;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        ed.push_back({u,v});
    }
    
    vector<pair<int,int>>quer;
    set<int>st;
    int i=0;
    while(i++<q){
        int e,f;
        cin>>e>>f;
        quer.push_back({e,f});
        if(e==1){
            f--;
            st.insert(f);
        } 
    }
    // set<int>s[n+1];
    s.clear();
    s.resize(n+1);
    for(int i=1;i<=n;i++)s[i].insert(col[i]);
    for(int i=0;i<m;i++){
        int u=ed[i].first;
        int v=ed[i].second;
        if(st.count(i)>0)continue;
        merge(u,v);
    }
     
    // for(int i=1;i<=n;i++){
    //     cout<<s[i].size()<<" ";
    // }
    cout<<endl;
    reverse(quer.begin(),quer.end());
    int k=0;
    while(k<q){
        if(quer[k].first==2){
            int node=quer[k].second;
            while(par[node]!=node)node=par[node];
            cout<<s[node].size()<<endl;
        }else{
            int node=quer[k].second-1;
            int u=ed[node].first;
            int v=ed[node].second;
            merge(u,v);
        }
        k++;
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