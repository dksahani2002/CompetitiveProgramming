#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int maxi[1001][1001];
long long solve(int n, int k, vector<int>&weight,vector<int>&taste){
        vector<int>w=weight;
         set<pair<int,int>>st;
        int ans=0;
        int dp[n+1];
        int r=n-1;
        for(int i=n-1;i>=0;i--){
            dp[i]=taste[i];
            ans=max(ans,dp[i]);
            if(st.size()>k){
                st.erase({w[r],r});
                r--;
            }
            if(!st.size()){
                st.insert({w[i],i});
                continue;
            }
            auto it=st.end();
            it--;
            dp[i]+=dp[(*it).second];
            ans=max(ans,dp[i]);
            st.insert({w[i],i});
        }
        return 1LL*ans;
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>w(n),taste(n);
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i++)cin>>taste[i];
    cout<<solve(n,k,w,taste)<<endl;
   
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