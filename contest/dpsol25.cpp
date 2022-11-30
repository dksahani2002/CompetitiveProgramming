#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>v;
int dp[10100];
int bS(int i){
    int l=0,r=i-1,ans=-1;
    while(l<=r){
        int  mid=(l+r)/2;
        if(v[i][1]>v[mid][0]){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}
int rec(int i){
    if(i==0)return v[i][2];
    if(dp[i]!=-1)return dp[i];
    int ans=rec(i-1);
    int j=bS(i);
    if(j!=-1)ans=max(ans,v[i][2]+rec(j));
    else ans=max(ans,v[i][2]);
    return dp[i]= ans;
}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n,vector<int>(3));
    for(int i=0;i<n;i++){
         cin>>v[i][1]>>v[i][0]>>v[i][2];
    }
    memset(dp,-1,sizeof(dp));
    sort(v.begin(),v.end());
    // dp[0]=v[0][2];
    // for(int i=1;i<n;i++){
    //     dp[i]=dp[i-1];//not take
    //     int idx=bS(i);
    //     if(idx!=-1)dp[i]=max(dp[i],v[i][2]+dp[idx]);
    //     else dp[i]=max(dp[i],v[i][2]);
    // }
    // cout<<dp[n-1]<<endl;
    cout<<rec(n-1)<<endl;
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