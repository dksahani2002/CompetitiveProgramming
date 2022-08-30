#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int  n,k;
    cin>>n>>k;
    if(n&1 && k==0){
        cout<<"No\n";
    } else{
        cout<<"Yes\n";
    }
    return;
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