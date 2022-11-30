#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100001][2];
const int mod=1e9+7;
void solve()
{
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<100001;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%mod;
    }

}
signed main()
{
    memset(dp,0,sizeof(dp));
    solve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])<<endl;
    }
}