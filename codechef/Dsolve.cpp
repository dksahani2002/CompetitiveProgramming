#include <bits/stdc++.h>
using namespace std;
// #define int long long
int dp[100005];
int k;
const int mod=1e9+7;
 
signed main()
// {   pre();
    int t;
    cin >> t>>k;
    dp[0]=1;
    for(int i=1;i<100005;i++){
       if(i>=k) dp[i]=(dp[i-1]+dp[i-k])%mod;
       else dp[i]=1;
    }
    for(int i=1;i<100005;i++){
         dp[i]+=dp[i-1];
         dp[i]%=mod;
    }
    while (t--)
    {
        // solve();
         int a,b;
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
        // return;
    }
}