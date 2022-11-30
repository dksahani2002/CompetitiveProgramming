#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>v;
const int mod=1e9+7;
int dp[100001];
int cnt[100001];
int len;
void rec(){
    for(int i=0;i<n;i++){
        cnt[i]=1;
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[i]>v[j]){
                if(dp[i]<dp[j]+1)dp[i]=dp[j]+1,cnt[i]=cnt[j];
                else if(dp[i]==dp[j]+1)cnt[i]+=cnt[j];
            }
        }
        len=max(len,dp[i]);
    }
}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n);
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=0;
    len=0;
    rec();
    for(int i=0;i<n;i++){
        if(dp[i]==len)ans+=cnt[i];
    }
    cout<<ans<<endl;

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