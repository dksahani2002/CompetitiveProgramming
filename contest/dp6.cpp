#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,n;
const int mod=1e9+7;
// int dp[100100];
int dp[1001][1001][2];
int rec(int i, int c1,int c2){
    if(i==n){
        if(c1<=k)return 1;
        return 0;
    }
    if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];
    int ans=0;
    if(c1<k){
        ans+=rec(i+1,c1+1,c2)+rec(i+1,1,!c2);
    }else{
        ans+=rec(i+1,1,!c2);
    }
    // if(c1<k && c2<k){
    //     ans+=rec(i+1,c1+1,0)+rec(i+1,0,c2+1);
        
    // }else if(c1<k){
    //     ans+=rec(i+1,c1+1,0);
    // }else if(c2<k){
    //     ans+=rec(i+1,0,c2+1);
    // }
    return dp[i][c1][c2]= ans%mod;
}
void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl; 
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