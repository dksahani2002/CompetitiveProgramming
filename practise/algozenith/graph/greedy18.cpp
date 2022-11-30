#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n),d(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>d[i];
    sort(v.begin(),v.end());
    sort(d.begin(),d.end());
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(v[i]-d[i]);
    }
    cout<<ans<<endl;
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