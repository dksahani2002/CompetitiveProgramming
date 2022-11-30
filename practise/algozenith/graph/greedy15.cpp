#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,ans=0;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=1;i<n;i++)ans+=max(0LL,v[i-1]-v[i]);
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