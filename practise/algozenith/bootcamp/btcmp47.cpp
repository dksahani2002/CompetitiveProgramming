#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
   int mod=1e9+7;
    int n,m;
    cin>>n>>m;
    int tot=0;
    tot+=((n*m)%mod)*((n*m-1)%mod);
    tot%=mod;
    int dec=0;
    dec+=(max(0LL,n-1)*max(0LL,m-2)*4)%mod;
    dec+=(max(0LL,n-2)*max(0LL,m-1)*4)%mod;
    dec%=mod;
    cout<<(tot-dec+mod)%mod<<endl;
}

signed main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t=1;
    // cin >> _t;
    while (_t--)
        solve();
}