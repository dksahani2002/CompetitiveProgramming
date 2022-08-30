#include <bits/stdc++.h>
using namespace std;
#define int long long
 set<int>st;
 int K;
 int dfs(int v, vector<vector<pair<int,int>>>g,vector<int>&vis,vector<int>indeg){
        vis[v]=1;
        int ans=0;
        sort(g[v].begin(),g[v].end());
        for(auto x:g[v]){
                int u=x.first;
                int w=x.second;
                if(vis[u])continue;
                if(indeg[u]>K){
                    indeg[u]--;
                    indeg[v]--;
                }else{
                    ans+=w;
                    ans+=dfs(u,g,vis,indeg);
                }
                
        }
        return ans;
 }
 void solve(int n , vector<int>&gf, vector<int>gt,vector<int>weight,int k){
    K=k;
        vector<vector<pair<int,int>>>g(n);
        vector<int>indeg(n,0);
        for(int i=0;i<gf.size();i++){
            g[gf[i]].push_back({gf[i],weight[i]});
            g[gt[i]].push_back({gf[i],weight[i]});
            indeg[gf[i]]++;
            indeg[gt[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indeg[i]>k)st.insert(i);
        }
        vector<int>vis(n,0);
        return dfs(0,g,vis,indeg);
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