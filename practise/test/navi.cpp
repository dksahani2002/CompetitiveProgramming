#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[1001];
int rec(int n){
    // if(n<0)return 
    if(n<3)return 1;
    if(n==3)return 2;
    if(dp[n]!=-1)return dp[n];
    return dp[n]= rec(n-1)+rec(n-3);

}
void solve()
{
    int n;
    cin>>n;
    cout<<rec(n)<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    rec(100);
    memset(dp,-1,sizeof(dp));
    while (t--)
    {
        solve();
    }
}


