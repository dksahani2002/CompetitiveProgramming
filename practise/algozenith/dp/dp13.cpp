#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s,t;
int n;
int dp[1001][1001];
int rec(int i, int j){
    if(i>=n || j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return  dp[i][j]= 1+rec(i+1,j+1);
    return  dp[i][j]= max(rec(i+1,j),rec(i,j+1));
}
void solve()
{
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());
    n=s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)dp[i][j]=-1;
    }
    cout<<n-rec(0,0)<<endl;
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