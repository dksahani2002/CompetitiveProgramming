#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e18+7;
int n;
vector<string>v,revv;
vector<int>cost;
int dp[100100][2];
int rec(int i, int rot){
    if(i>=n)return 0;
    int prev=i-1;
    if(dp[i][rot]!=-1)return dp[i][rot];
    int ans=1e18;
    if(rot){
         if(v[i]>=revv[prev]){
            ans=min(ans,rec(i+1,0));
         }
         if(revv[i]>=revv[prev]){
            ans=min(ans,cost[i]+rec(i+1,1));
         }
    }else{
        if(v[i]>=v[prev]){
            ans=min(ans,rec(i+1,0));
         }
         if(revv[i]>=v[prev]){
            ans=min(ans,cost[i]+rec(i+1,1));
         }
    }
    return  dp[i][rot]=  ans;

}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n); 
    revv.clear();
    revv.resize(n);
    cost.clear();
    cost.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>cost[i];
    for(int i=0;i<n;i++){
        cin>>v[i];
        revv[i]=v[i];
        reverse(revv[i].begin(),revv[i].end());
    }
    int ans=min(rec(1,0),cost[0]+rec(1,1));
    if(ans==1e18){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;


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