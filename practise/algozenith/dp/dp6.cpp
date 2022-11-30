#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s,t;
int ans;
int dp[1001][1001];
int rec(int i, int j){
    if(i>=s.size() || j>=t.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int count=0;
    if(s[i]==t[j])count=1+rec(i+1,j+1);
    else rec(i+1,j),rec(i,j+1);
    return dp[i][j]= count;
}
void solve()
{
 cin>>s>>t;
 memset(dp,-1,sizeof(dp));
 ans=0;


 rec(0,0);
 for(int i=0;i<s.size();i++){
    for(int j=0;j<t.size();j++){
        ans=max(ans,rec(i,j));
        // cout<<dp[i][j]<<" ";
    }
    cout<<endl;
 }
cout<<ans<<endl;
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