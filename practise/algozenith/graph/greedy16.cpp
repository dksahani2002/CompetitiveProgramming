#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,ans=0;cin>>n; 
    vector<int>vx(n),vy(n);
    for(int i=0;i<n;i++)cin>>vx[i]>>vy[i];
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    int x=vx[n/2];
    int y=vy[n/2];
    
    for(int i=0;i<n;i++)ans+=abs(vx[i]-x)+abs(vy[i]-y);
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