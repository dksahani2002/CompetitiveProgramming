#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
int n;
int dp[101][101][101];
int rec(int l,int r,int no){
    if(l>r)return 0;
    if(dp[l][r][no])return dp[l][r][no];
    //not lach
    int ans=(no+1)*(no+1)+rec(l+1,r,0); 
    //lach
    for(int i=l+1;i<=r;i++){
       if(v[l]==v[i]) ans=max(ans,rec(l+1,i-1,0)+rec(i,r,no+1));
    }
    return dp[l][r][no]= ans;
}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<rec(0,n-1,0)<<endl;
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