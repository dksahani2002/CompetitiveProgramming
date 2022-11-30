#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int mod=1e9+7;
vector<vector<int>>g;
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    int indeg[n+1]={0};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    int cnt=0;
    vector<int>ans;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            cnt++;
            int node=q.top();q.pop();
            ans.push_back(node);
            for(auto v:g[node]){
                if(--indeg[v]==0){
                    q.push(v);
                }
            }
        }
    }
    // cout<<cnt<<endl;
    if(cnt!=n){
        cout<<-1<<endl;
        return;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

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