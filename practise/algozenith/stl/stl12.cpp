#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    int tot_area=abs(x1-x2)*abs(y1-y2)+abs(x3-x4)*abs(y3-y4);
    int nx1=max(x1,x3);
    int ny1=max(y1,y3);
    int nx2=min(x2,x4);
    int ny2=min(y2,y4);
    int area=0;
    if(nx1<=nx2 && ny1<=ny2)area=abs(nx1-nx2)*abs(ny1-ny2);
    cout<<area<<" "<<tot_area-area<<endl;
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