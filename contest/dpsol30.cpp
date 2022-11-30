#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int mod=1e9+7;
 string s,t;
 int dp[1001][1001];
 int rec(int i, int j){
    if(i==-1)return 1e9;
    if(j==-1){
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int k;
    for( k=j;k>=0;k--){
        if(s[i]==t[k]){
             break;
        }
    }
    if(k==-1)return dp[i][j]= 1;
    return  dp[i][j]= min(1+rec(i-1,k-1),rec(i-1,j));
 }
void solve()
{
     cin>>s>>t;
     memset(dp,-1,sizeof(dp));
     int ans=rec(s.size()-1,t.size()-1);
     cout<<(ans>s.size()?-1:ans)<<endl;

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