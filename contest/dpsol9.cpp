#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin>>n>>m;
    int dp[n+1][m+1]={0};
    for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            cin>>dp[i][j];
         } 
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]+=dp[i][j-1];
        }
    } 
    int res=-1e9;
    for(int j=1;j<=m;j++){
        for(int i=0;i<j;i++){
            vector<int>v(n);
            for(int k=0;k<n;k++){
                v[k]=dp[k+1][j]-dp[k+1][i];
            }
            int ans=-1e9;
            int sum=0;
            for(int i=0;i<n;i++){
                ans=max(ans,v[i]);
                sum+=v[i];
                if(sum<0){
                    sum=0;
                }else{
                    ans=max(ans,sum);
                }
            }
            res=max(res,ans);
        }
    } 
    cout<<res<<endl;
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