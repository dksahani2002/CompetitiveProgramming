#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt=0;
     if(b>a)cnt++; 
     if(c>a)cnt++;
     if(d>a)cnt++;
     cout<<cnt<<endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}