#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int rec(int n, int k){
    if(n==1)return 1;
    return (rec(n-1,k)+k-1)%n+1;
}
void solve()
{
    int n,k;cin>>n>>k;
    cout<<rec(n,k)<<endl;

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