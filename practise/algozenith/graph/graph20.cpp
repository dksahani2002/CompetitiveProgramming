#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<vector<int>>g(n,vector<int>(n));
  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    vector<int>q;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        x--;
        q.push_back(x);
    }
    vector<int>res;
    for(int k=n-1;k>=0;k--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=min(g[i][j],g[i][q[k]]+g[q[k]][j]);
            }
        }
        int ans=0;
        for(int i=k;i<n;i++){
            for(int j=k;j<n;j++){
                 ans+=g[q[i]][q[j]];
            }
        }
        res.push_back(ans);
    }
    reverse(res.begin(),res.end());
    for(auto v:res){
        cout<<v<<" ";
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