#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int mxpos=v[0];
    int mxneg=v[0];
    int ans=v[0];
    for(int i=1;i<n;i++){
        int temp1=max({v[i],mxpos*v[i],mxneg*v[i]});
        int temp2=min({v[i],mxpos*v[i],mxneg*v[i]});
        mxpos=temp1;
        mxneg=temp2;
        ans=max(ans,mxpos);
    }
    cout<<ans<<endl;
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