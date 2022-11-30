#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,q;
vector<int>par;
vector<int>dis;
pair<int,int> find(int node){
     if(par[node]==node)return {node,0};
     pair<int,int>temp=find(par[node]);
     dis[node]+=temp.second;
     par[node]=temp.first;
     return {par[node],dis[node]};
}
// int find(int node){
//     if(par[node]==node)return node;
//     int temp=find(par[node]);
//     dis[node]+=dis[temp];
//     par[node]=temp;
//     return temp;
// }
void merge(int u, int v,int w){
    auto x=find(u);
    auto y=find(v);
    int p1=x.first;
    int p2=y.first;
    par[p2]=p1;
    dis[p2]=w+x.second-y.second;        
    // int p1=find(u);
    // int p2=find(v);
    // par[p2]=p1;
    // dis[p2]=w+dis[p1]-dis[p2];
}
void solve()
{
    cin>>n>>q;
    par.clear();
    par.resize(n+1);
    dis.clear();
    dis.resize(n+1,0);
    for(int i=0;i<=n;i++){
         par[i]=i;
    }
    while(q--){
        int id;cin>>id;
        if(id==0){
            int x,y,z;cin>>x>>y>>z;
            merge(x,y,z);

        }else{
           int x,y;cin>>x>>y;
           auto p1=find(x);
           auto p2=find(y);
           if(p1.first!=p2.first){
            cout<<"?"<<endl;
            continue;
           }
            cout<<p2.second-p1.second<<endl;
            // if(p1!=p2){
            //     cout<<"?"<<endl;
            //     continue;
            // }
            // cout<<dis[p2]-dis[p1]<<endl;
        }
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