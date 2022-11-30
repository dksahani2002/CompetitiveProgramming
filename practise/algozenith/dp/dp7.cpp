#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s1,s2,s3;
int dp[101][101][101];
int rec(int i, int j, int k){
    if(i>=s1.size() || j>=s2.size() || k>=s3.size())return 0;
    int ans=0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(s1[i]==s2[j] && s2[j]==s3[k])return dp[i][j][k]= 1+rec(i+1,j+1,k+1);
    ans=max(ans,rec(i+1,j,k));
    ans=max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i,j,k+1));
    return dp[i][j][k]=ans;
    
}
void solve()
{
    cin>>s1>>s2>>s3;
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            for(int k=0;k<s3.size();k++)dp[i][j][k]=-1;
        }
    }
    cout<<rec(0,0,0)<<endl;

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