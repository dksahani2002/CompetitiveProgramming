#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,n;
// int dp[100100];
// map<int,int>mp;
// int rec(int i, vector<int>&v){
//     // if(i>=v.size())return 0;
//     if(i==v.size()-1)return v[i];
//     int ans=INT_MIN;
//     if(mp.find(i)!=mp.end())return mp[i];
//     for(int j=1;j<=k;j++){
//        if(i+j<n) ans=max(ans,v[i]+rec(i+j,v));
//     }
//     return mp[i]= ans;
// }
void solve()
{
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cin>>k;
    
    // cout<<rec(0,v)<<endl;
    int dp[n];
    dp[0]=v[0];
    deque<int>dq;
    dq.push_front(0);
    for(int i=1;i<n;i++){
        // dp[i]=dp[i-1]+v[i];
        dp[i]=v[i]+dp[dq.front()];   
        while(!dq.empty() && dp[dq.back()]<dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i-dq.front()>=k)dq.pop_front();
    }
    cout<<dp[n-1]<<endl;
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