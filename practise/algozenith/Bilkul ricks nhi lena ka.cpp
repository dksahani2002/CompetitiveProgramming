#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;cin>>a>>b;
    int ans=0;
    for(int i=31;i>=0;i--){
        if(a&(1<<i) && b&(1<<i)){
             ans+=2*(1<<i);
        }else if(a&(1<<i) || b&(1<<i)){
            ans+=(1<<i);
        }
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