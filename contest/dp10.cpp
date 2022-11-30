#include <bits/stdc++.h>
using namespace std;
#define int long long
 int n,m;
 int dp[1001][1001][2][2];
 int rec(int i,int j,string&s,string&t,int ea,int eb){
    if(i>=n || j>=m){
        if(ea==0 && eb==1)return 0;
        return INT_MIN;
    }
    if(dp[i][j][ea][eb]!=-1)return dp[i][j][ea][eb];
    int ans=INT_MIN;
    int x=ea;
    int y=eb;
    if(s[i]==t[j]){
        return dp[i][j][x][y]= max(1+rec(i+1,j+1,s,t,(ea+=(s[i]=='a'))%2,(eb+=(s[i]=='b'))%2),max(rec(i+1,j,s,t,ea,eb),rec(i,j+1,s,t,ea,eb)));         
        
    }
    int res=max(rec(i+1,j,s,t,ea,eb),rec(i,j+1,s,t,ea,eb));
    return dp[i][j][x][y]=max(ans,res);
 }
void solve()
{
    string s,t;
    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0,s,t,0,0);
    if(ans<=0){
        cout<<0<<endl;
        return;
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