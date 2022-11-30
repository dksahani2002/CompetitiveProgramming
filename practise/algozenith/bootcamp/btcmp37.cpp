#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>v;
// int dp[1001][1001];
vector<vector<int>>dp;
int rec(int i,int last){
    if(i>=v.size())return 0;
    if(dp[i][last]!=-1)return dp[i][last];
    int ans=rec(i+1,last);
    if(v[i][0]<v[last][0] && v[i][1]<v[last][1]){
        ans=max(ans,v[i][2]+rec(i+1,i));
    }
    return  dp[i][last]=ans;
}
void solve()
{
    int n;cin>>n;
    v.clear();
    for(int i=0;i<n;i++){
        int l,b,h;cin>>l>>b>>h;
        v.push_back({l,b,h});
        v.push_back({l,h,b});
        v.push_back({b,l,h});
        v.push_back({b,h,l});
        v.push_back({h,l,b});
        v.push_back({h,b,l});
    }
    int mx=INT_MAX;
    v.push_back({mx,mx,0});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    n=v.size();
    dp.clear();
    dp.assign(n+5,vector<int>(n+5,-1));
    cout<<rec(0,0)<<endl;

}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}