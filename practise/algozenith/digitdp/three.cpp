#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
string p;
int dp[100010][2][2];
int rec(int i, int t1, int t2){
    if(i==p.size())return (t1&&t2);
    int lo=0;
    int ans=0;
    if(dp[i][t1][t2]!=-1)return dp[i][t1][t2];
    if(t1==0)lo=p[i]-'A';
    for(int j=lo;j<26;j++){
        int lt1=t1,lt2=t2;
        if(j<p[i]-'A'){
            if(t1==1)lt2=0;
        }else if(j>p[i]-'A'){
            lt1=1,lt2=1;
        }
        ans+=rec(i+1,lt1,lt2);
        ans%=mod;
    }
    return dp[i][t1][t2]=ans;
}
void solve()
{
    cin>>p;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}