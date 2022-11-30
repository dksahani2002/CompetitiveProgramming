#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
class fun{
    int rate=0,val=0;
    static int x;
    public:
     void in(){
        cin>>rate>>val;
     }
     void show(){
        cout<<x<<endl;
        cout<<rate<<" "<<val<<endl;
        x=rate+val;
        cout<<x<<endl;
        
     }
};
// fun::x=0;
void solve()
{
    fun a,b;
    a.in();
    a.show();
    // b.show();
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}