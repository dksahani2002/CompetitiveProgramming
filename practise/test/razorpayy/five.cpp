#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
string toBinary(int n, int len)
{
    string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }

    return binary;
}
void solve()
{
    int n=100;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if( (i+j)==(2*(i^j))){
                
                // cout<<(i+j)<<" "<<2*(i^j)<<endl; 
            int len=7;
            cout<<i<<" "<<j<<endl;
            cout << toBinary(i+j, len)<<endl;
            cout << toBinary(i, len)<<endl;
            cout << toBinary(j, len)<<endl;
            cout<<endl;
            }

        }
    }
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