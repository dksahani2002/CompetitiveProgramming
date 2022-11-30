#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;

vector<int>countPrime(int n){
    vector<int>v;
    int m=n;
    int xx=n;
    if(n%2==0)v.push_back(n/2);
    while(n%2==0){ 
        n/=2;
    }
    for(int i=3;i<=n;i+=2){
        if(n%i==0)v.push_back(xx/i);
        while(n%i==0){
            n/=i;
        }
    }
    return v;
}
void dfs(int node,int par){
    cout<<node<<endl;
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
        }
    }
}
void solve()
{
    int x,y,m;cin>>x>>y>>m;
   g.clear(); g.resize(1001);
    queue<int>q;
    q.push(x);
    // q.push(y);

    while(!q.empty()){
        auto p=q.front();q.pop();
        // cout<<p<<endl;
        g[p]=countPrime(p);
        for(auto e:g[p]){
           if(e>2)q.push(e);
        }
    }
    dfs(12,-1);
    // for(auto e:v2){
    //     cout<<e<<" ";
    // }
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