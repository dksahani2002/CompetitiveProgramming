#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
 
int dp[501][501];
int mx[501][501],mn[501][501];
int rec(int l, int r,vector<int>&v){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=INT_MAX;
    for(int i=l;i<=r;i++){
        int left=rec(l,i-1,v);
        int right=rec(i+1,r,v);
        int mxl=(i-1>=l)?mx[l][i-1]:0;
        int mnl=(i-1>=l)?mn[l][i-1]:0;
        int mxr=(r>=i+1)?mx[i+1][r]:0;
        int mnr=(r>=i+1)?mn[i+1][r]:0;
        ans=min(ans,mxl+mnl+mxr+mnr+left+right);
    }
    return dp[l][r]= ans;
}
void solve()
{
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        int mini=1e18;
        int maxi=-1e18;
        for(int j=i;j<n;j++){
            mini=min(mini,v[j]);
            maxi=max(maxi,v[j]);
            mx[i][j]=maxi;
            mn[i][j]=mini;
        }
    }
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++)dp[i][j]=-1;
    }
    cout<<rec(0,n-1,v)<<endl;

}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}