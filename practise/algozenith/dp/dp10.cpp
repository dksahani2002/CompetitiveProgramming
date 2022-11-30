#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int dp[n+1];
    int last[26]={-1};
    int sum[n+1];
    dp[0]=1;
    sum[0]=1;
    for(int i=1;i<=n;i++){
        int id=last[s[i-1]-'A'];
        dp[i]=sum[i-1];
        if(id>0){
            dp[i]=(dp[i]-sum[id-1] +mod)%mod;
            dp[i]%=mod;
        }
        sum[i]=sum[i-1]+dp[i];
        sum[i]%=mod;
        last[s[i-1]-'A']=i;
    }
    cout<<sum[n]<<endl;
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