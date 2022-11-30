#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    vector<int>sum(n+1,0);
    vector<int>dp(n+1,0);
    vector<int>last(26,-1);
    dp[0]=1;
    sum[0]=1;
    const int mod=1e9+7;
    for(int i=1;i<=n;i++){
        int ind=s[i-1]-'A';
        dp[i]=sum[i-1];
        if(last[ind]>0){
            dp[i]-=sum[last[ind]-1];
            dp[i]=(dp[i]%mod+mod)%mod;
        }
        sum[i]=(sum[i-1]+dp[i])%mod;
        last[ind]=i;
    }
    cout<<sum[n]<<endl;
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