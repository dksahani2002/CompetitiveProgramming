#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,l;cin>>n>>l;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    v.insert(v.begin(),0);
    v.push_back(l);
    int d=-1e9;
    for(int i=1;i<n+2;i++){
        d=max(d,v[i]-v[i-1]);
    }
    cout<<(d+1)/2<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}