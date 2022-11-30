#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
   int n,m;
   cin>>n>>m;
   vector<vector<int>>v(n,vector<int>(m));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++)cin>>v[i][j];
   }
   int dp[n][m];
   memset(dp,0,sizeof(dp));
   int ans=0;
  for(int i=0;i<n;i++){
       for(int j=0;j<m;j++) {
   
           if(v[i][j]){ 
             dp[i][j]=j==0?1:dp[i][j-1]+1;
             int width=dp[i][j];
             for(int k=i;k>=0;k--){
                 width=min(width,dp[k][j]);
                 ans=max(ans,width*(i-k+1));
             }
           }
        }
   }
   cout<<ans<<endl;
    return;
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