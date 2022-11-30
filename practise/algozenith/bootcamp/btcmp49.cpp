#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;

void solve()
{
        int n,k;cin>>n>>k;
        vector<int>v(n+1),mp(k,-1);
        for(int i=1;i<=n;i++)cin>>v[i];
         
        int sum=0,ans=0;
        for(int i=1;i<=n;i++){
            sum+=v[i];
            sum=(sum+k)%k;

            if(mp[sum]!=-1){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
             
        }
        cout<<ans<<endl;
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