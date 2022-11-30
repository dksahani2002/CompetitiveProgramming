#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
int dp[1001][1001];
int rec(int i, int j){
    if(i<0 || j<0 || j>=m)return -1e9;
    // if(i==0)return g[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=g[i][j];
     ans= max(ans,rec(i-1,j-1));
     ans= max(ans,rec(i-1,j));
     ans= max(ans,rec(i-1,j+1));
    return dp[i][j]=ans;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+5,vector<int>(m+5));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            dp[i][j]=-1;
        }
    }
    // rec(n-1,m-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]<rec(i,j)){
                cout<<0;
            }else{
                cout<<1;
            }
        }
        cout<<endl;
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