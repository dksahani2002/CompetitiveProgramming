#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    // int n;cin>>n;
    string s;cin>>s;
    int n=s.size();
    int dp[n+1];
    dp[0]=1;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(mp.find(s[i-1]-'a')!=mp.end()){
            dp[i]-=dp[mp[s[i-1]-'a']]; 
        } 
        mp[s[i-1]-'a']=i-1; 
    }
      cout<<dp[n]<<endl;
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