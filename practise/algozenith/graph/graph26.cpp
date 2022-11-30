#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,q;
vector<int>par,rnk;
int find(int node){
    if(par[node]==-1)return node;
    return par[node]=find(par[node]);
}
void merge(int u, int v){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2)return;
    if(rnk[p1]>rnk[p2]){
        par[p2]=p1;
    }else if(rnk[p1]==rnk[p2]){
        par[p2]=p1;
        rnk[p1]+=1;
    }else{
        par[p1]=p2;
    }
}
void solve()
{
    cin>>n>>q;
    par.clear();
    par.resize(n+1,-1);
    rnk.clear();
    rnk.resize(n+1,1);
    while(q--){
        int x;cin>>x;
        int u,v;cin>>u>>v;
        if(x==1){
            if(find(u)!=find(v)){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }else{
            merge(u,v);
        }
    }
}
signed main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}