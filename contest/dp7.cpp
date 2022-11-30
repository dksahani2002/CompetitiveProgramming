#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,h,s,t;
vector<int>v;
int dp[1001][1001];
int rec(int i, int ne){
    if(i>=n)return ne*t;
    if(dp[i][ne]!=-1)return dp[i][ne];
    int ans=0;
    if(ne<v[i]){
        ans=v[i]*s+(v[i]-ne)*h+rec(i+1,v[i]);
    }else{
        int cost=INT_MAX;
        for(int e=v[i];e<=ne;e++){
            cost=min(cost,e*s+(ne-e)*t+rec(i+1,e));
        }
        ans+=cost;
    }
    return dp[i][ne]= ans;

}
void solve()
{
    cin>>n>>h>>s>>t;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
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