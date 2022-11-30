#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
void solve()
{
    cin>>n>>m;
    int indeg[n+1]={0};
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[v].push_back(u);
        indeg[u]++;
    }
    int lbl=n;
    priority_queue<int>q;
    vector<int>label(n+1);
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);   
        }
    }
    while(!q.empty()){
        int node=q.top();q.pop();
        label[node]=lbl--;
        for(auto v:g[node]){
            if(--indeg[v]==0)q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<label[i]<<" ";
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