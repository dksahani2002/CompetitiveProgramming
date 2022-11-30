#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n,m,k;
int dp[2001][2][2001];
int rec(int i,int prev,int change){
    if(change>k)return 0;
    if(i>=n) return (change==k);
    if(dp[i][prev][change]!=-1)return dp[i][prev][change];
    int ans=0;
    if(i==0){
        ans+=rec(i+1,prev,change);
        ans%=mod;
    }else{
        ans+=rec(i+1,prev,change)+(m-1)*rec(i+1,!prev,change+1);
        ans%=mod;
    }
    return dp[i][prev][change]= ans%mod;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][0][j]=-1;
            dp[i][1][j]=-1;
        }
    }
    int ans=rec(0,0,0);
    cout<<(ans*m)%mod<<endl;
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