#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>diff,par;
pair<int,int> find(int u){
    if(par[u]==-1)return {u,0};
    pair<int,int>tmp=find(par[u]);
    diff[u]+=tmp.second;
    par[u]=tmp.first;
    return {par[u],diff[u]};
}
void relate(int u, int v,int w){
    pair<int,int> p1=find(u);
    pair<int,int> p2=find(v);
    par[p2.first]=p1.first;
    diff[p2.first]=w+diff[u]-diff[v];
}
void solve()
{   int n,q;
    cin>>n>>q;
    diff=vector<int>(n,0);
    par=vector<int>(n,-1);
    while(q--){
        int x,u,v,w;
        cin>>x;
        if(x==0){ 
            cin>>u>>v>>w;
            relate(u,v,w);
        }else{
            cin>>u>>v;
            pair<int,int>p1=find(u);
            pair<int,int>p2=find(v);
            if(p1.first!=p2.first){
                cout<<"?"<<endl;
            }else{
                cout<<p2.second-p1.second<<endl;
            }
        }

    }

}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {   
        solve();
    }
}