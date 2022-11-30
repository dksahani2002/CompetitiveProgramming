#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,z;
vector<int>v;
int done[51][51];
int dp[51][51][51];

int rec(int l, int r,int val){
    if( l==r){
        if(val==v[l])return 0;
        return 1e9;
    }
    if(done[l][r])return dp[l][r][val];
    for(int i=0;i<50;i++)dp[l][r][i]=1e9;
    for(int mid=l;mid<r;mid++){
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                int left=rec(l,mid,i);
                int right=rec(mid+1,r,j);
                dp[l][r][(l*x+r*y+z)%50]=min(dp[l][r][(l*x+r*y+z)%50],left+right+i*j);
            }
        }
    }
    done[l][r]=1;
    return dp[l][r][(l*x+r*y+z)%50];
}
void solve()
{
    cin>>n>>x>>y>>z;
    v.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=1e9;
    for(int i=0;i<50;i++){
        ans=min(ans,rec(0,n-1,i));
    }
    cout<<ans<<endl;
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