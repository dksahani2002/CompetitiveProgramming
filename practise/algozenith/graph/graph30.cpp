#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
vector<int>weight;
int n,m,cnt,ans;
int flag;
int dfs(int node,int par, int val){
    int sum=weight[node];
    for(auto v:g[node]){
        if(v!=par){
              sum+=dfs(v,node,val);
        } 
    }
    if(sum==val){
        sum=0;
        cnt++;
    }
    if(sum>val)flag=1;
    return sum;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    weight.clear();
    weight.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cin>>weight[i+1];
    }
    cnt=0;
    ans=0;   
    flag=0;  
    int x=dfs(1,-1,5);
    if(flag){
        cout<<"No\n";
    }else{
        cout<<cnt<<endl;
        cout<<"YES\n";
    }
         
     
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