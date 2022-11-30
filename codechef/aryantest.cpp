 #include <bits/stdc++.h>
using namespace std;
#define int long long
 void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,g,vis);
        }
    }
 }
void solve()
{
    int n;cin>>n;
     string s;cin>>s;
    vector<vector<int>>g(2*n+1);
    vector<int>res;
    stack<int>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')st.push(i+1);
        else{
            g[i+1].push_back(st.top());
            g[st.top()].push_back(i+1);
            int t=st.top();
            st.pop();
            if(st.empty()){
                for(auto j:res){
                    g[i+1].push_back(j);
                    g[j].push_back(i+1);
                }
                res.push_back(t);
            }
        }
    }
     
    
     
    vector<int>vis(2*n+1,0);
    int ans=0;
    for(int i=1;i<=2*n;i++){
        if(vis[i]==0){
            ans++;
            dfs(i,g,vis);
            
        }
    }
    cout<<ans<<endl;
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