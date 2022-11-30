#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]-=(i+1);
    }
    sort(v.begin(),v.end());
    int mid=n/2;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(v[i]-v[mid]);
    }
    cout<<ans<<endl;
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