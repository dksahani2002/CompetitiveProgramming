#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    queue<int>flips;
    int res=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x!=(flips.size()%2?0:1)){
            res++;
            flips.push(i+k-1);
        }
        if(!flips.empty() && flips.front()<=i)flips.pop();
    }
    cout<< (flips.empty()?res:-1)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}