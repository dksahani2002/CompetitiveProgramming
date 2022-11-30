#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,n;
const int mod=1e9+7;
int dp[100][101][101];
int rec(int i, int sum,int l,vector<int>&v){
     if(i>=v.size()){
        return (sum==n && l<=k);
     }
     if(dp[i][sum][l]!=-1)return dp[i][sum][l];
     int ans=0;
     if(sum+v[i]<=n){
        ans+=rec(i,sum+v[i],l+1,v)+rec(i+1,sum,l,v);
     }else{
        ans+=rec(i+1,sum,l,v);
     }
    // return dp[left][sum]= ans%mod;
    return dp[i][sum][l]=ans;
}
void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=i+1;
    }
    cout<<rec(0,0,0,v)<<endl; 
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