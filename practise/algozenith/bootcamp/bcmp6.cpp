#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    int ans=0,i=1;
    while(1){
        int val=n-(i*(i+1))/2;
        if(val<0)break;
        if(val%i==0)ans++;
        i++;
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