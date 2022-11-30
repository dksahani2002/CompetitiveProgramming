#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<fixed<<setprecision(7)<<sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<<" "<<(double)(abs(x1-x2)+abs(y1-y2))<<endl;
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