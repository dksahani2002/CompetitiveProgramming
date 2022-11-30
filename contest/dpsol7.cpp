#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n,k;
int dp[1500][1500];
int rec(int i, int left,vector<int>&v){
    if(i>=v.size())return left>=0;
    if(left<0)return 0;
    //take
    if(dp[i][left]!=-1)return dp[i][left];
    return  dp[i][left]= v[i]*rec(i+1,left-1,v)+rec(i+1,left,v)%mod;
}
void solve()
{
    cin>>n>>k;
    map<int,int>st;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st[x]++;
    }
    vector<int>v;
    int j=0;
    for(auto i:st){
         v.push_back(i.second);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,k,v)<<endl;

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