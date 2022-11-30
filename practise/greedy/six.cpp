#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int x,y;cin>>x>>y;
    if(x>=y){
        cout<<x-y<<endl;
        return;
    }
    int ans=0;
    while(y>x){
        if(y&1)y++;
        else y/=2;
        ans++;
    }
    ans+=x-y;
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