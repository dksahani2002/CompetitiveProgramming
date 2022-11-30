#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
int dp[1000001][4];
int rec(int i, int state){
    if(i==-1)return 1;
    auto &ans=dp[i][state];
    if(ans)return ans;
    if(state==0){
        ans+=(rec(i-1,state)+rec(i-1,1))%mod;
    }else if(state==1){
        ans+=rec(i-1,1)+rec(i-1,2);
    }else if(state==2){
        ans+=(rec(i-1,0)+rec(i-1,3))%mod;
    }else if(state==3){
        ans+=rec(i-1,2)%mod;
    }
    ans%=mod;
    return ans;
}
void solve()
{
    cin>>n;
    cout<<rec(n-1,0)<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    memset(dp,0,sizeof(dp));
    while (t--)
    {
        solve();
    }
}