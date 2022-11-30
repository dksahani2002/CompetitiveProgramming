#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s;
int dp[1001][1001];
int rec(int i, int cnt){
    if(cnt<0)return 0;
    if(i>=s.size()){
        return cnt==0;
    }
    if(dp[i][cnt]!=-1)return dp[i][cnt];
    int ans=0;
    if(s[i]=='('){
        ans+=rec(i+1,cnt+1);
    }else if(s[i]==')'){
        ans+=rec(i+1,cnt-1);
    }else{
        ans+=rec(i+1,cnt+1)+rec(i+1,cnt-1);
    }
    return  dp[i][cnt]= ans%mod;
}
void solve()
{
    cin>>s;
    // memset(dp,-1,sizeof(dp));
    int n=s.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<rec(0,0)<<endl;

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