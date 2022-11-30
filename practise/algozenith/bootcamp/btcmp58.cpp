#include <bits/stdc++.h>
using namespace std;
#define int long long
int rec(int a,int b){
    if(!a)return b;
    return rec((a&b)<<1,a^b);
}
void solve()
{
    int a,b;cin>>a>>b;
     
    cout<<rec(a,b)<<endl;
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