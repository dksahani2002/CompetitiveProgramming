#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int dp[1000001][4];
// string s
int n;
int rec(int i, int s){
    if(i==-1)return 1;
    if(dp[i][s]!=-1)return dp[i][s];
    int ans=0;
    if(s==0){
        ans+=rec(i-1,0)+rec(i-1,1);
    }else if(s==1){
        ans+=rec(i-1,1)+rec(i-1,2);
    }else if(s==2){
        ans+=rec(i-1,0)+rec(i-1,3);
    }else if(s==3){
        ans+=rec(i-1,2);
    }
    return dp[i][s]= ans%mod;
}
void solve()
{
    cin>>n;
    cin>>s;
    // v.resize(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    int ans=rec(n-1,0);
    cout<<ans<<endl;
}
signed main()
{   
    memset(dp,-1,sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}