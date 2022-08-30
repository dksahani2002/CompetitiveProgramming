#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int a,b,c;
    cin>>a>>b>>c;
    int x,y,z;
    z=c;
    y=b+c*2;
    x=a+y*1;
    cout<<x<<" "<<y<<" "<<z<<endl;
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