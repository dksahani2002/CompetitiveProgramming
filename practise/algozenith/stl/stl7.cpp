#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    int ans=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans+=2;
            if(i*i==n)ans-=1;
        }
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