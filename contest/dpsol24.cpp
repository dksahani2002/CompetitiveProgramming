#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>v;
int dp[101][101];
// think in term of first element handling how we can get rid of that first element
int rec(int l, int r){
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1+rec(l+1,r);
    if(l<r && v[l]==v[l+1])ans=min(ans,1+rec(l+2,r));  
    for(int i=l+2;i<=r;i++){
        if(v[i]==v[l]){
            ans=min(ans,rec(l+1,i-1)+rec(i+1,r));
        }
    }
    return  dp[l][r]= ans;
}
void solve()
{
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
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