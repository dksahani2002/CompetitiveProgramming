#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>p;
void dfs(int node,vector<int>&vis,vector<vector<int>>&g,set<int>&st1,set<int>&st2){
    vis[node]=1;
    st1.insert(node);
    st2.insert(p[node]);
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,vis,g,st1,st2);
        }
    }
}
bool check(int i,vector<vector<int>>&edges){
        vector<vector<int>>g(n+1);
        for(int j=i;j<edges.size();j++){
            g[edges[j][0]].push_back(edges[j][1]);
            g[edges[j][1]].push_back(edges[j][0]);
        }
        vector<int>vis(n+1,0);
        for(int j=i;j<edges.size();j++){
            int node=edges[j][0];
            if(!vis[node]){
                set<int>st1,st2;
                dfs(node,vis,g,st1,st2);
                if(st1!=st2)return false;
            }
        }
        return true;
}
bool cmp(vector<int>&a, vector<int>&b){
    return a[2]<b[2];
}
void solve()
{
    cin>>n>>m;
    p.clear();
    p.resize(n+1);
    for(int i=1;i<=n;i++)cin>>p[i];
    vector<vector<int>>edges(m+1,vector<int>(3));
    for(int i=0;i<m;i++){ 
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    int ch=true;
    for(int i=1;i<=n;i++){
        if(i!=p[i])ch=false;
    }
    if(ch){
        cout<<-1<<endl;
        return;
    }
    sort(edges.begin(),edges.end(),cmp);
     
    int l=1;
    int r=m;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,edges)){
            l=mid+1;
            ans=edges[mid][2];
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl; 
}

signed main()
{
 
    int _t=1;
    // cin >> _t;
    while (_t--)
        solve();
}