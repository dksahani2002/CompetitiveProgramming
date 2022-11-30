#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<pair<int,int>>>g;
int dfs(int node, int des, int left, int move){
    if(node==des && left==0)return move;
    if(node==des || left<0)return 1e9;
    int ans=1e9;
    for(auto x:g[node]){
        int neigh=x.first;
        int w=x.second;
        ans=min(ans,dfs(neigh,des,left-1,max(move,w)));
    }
    return ans;
}
int minDurability(int n,int m,vector<int>from,vector<int>to,vector<int>temp,int s,int t,int d){
    g.clear();
    g.resize(n);
    for(int i=0;i<m;i++){
        int u=from[i]-1;
        int v=to[i]-1;
        int w=temp[i];
        g[u].push_back({v,w});
    }
    int ans=dfs(s-1,t-1,d,-1e9);
    if(ans==-1e9)return -1;
    return ans;
    
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>fromi(m),toi(m),temp(m);
    for(int i=0;i<m;i++)cin>>fromi[i];
    for(int i=0;i<m;i++)cin>>toi[i];
    for(int i=0;i<m;i++)cin>>temp[i];
    int s,t,d;
    cin>>s>>t>>d;
    cout<<minDurability(n,m,fromi,toi,temp,s,t,d)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}