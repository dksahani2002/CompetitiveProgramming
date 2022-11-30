#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
string s;
vector<int>dp;
int rec(int i){
    if(i>=s.size())return 1;
    if(s[i]=='0')return dp[i]=0;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    int op1=s[i]-'0';
    ans+=rec(i+1);
    ans%=mod;
    int op2=0;
    if(i+1<s.size()){
        op1*=10;
        op2=op1+s[i+1]-'0';
        if(op2>9 && op2<27)ans+=rec(i+2);
    }
    ans%=mod;
    return  dp[i]=ans;
}
void solve()
{
    cin>>s;
    int n=s.size();
    dp.resize(n+1,-1);
    cout<<rec(0)<<endl;
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}