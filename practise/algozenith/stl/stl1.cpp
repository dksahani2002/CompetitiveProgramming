#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v1(n),v2(n-1),v3(n-2);
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<n-1;i++)cin>>v2[i];
    for(int i=0;i<n-2;i++)cin>>v3[i];
    int ans1=v1[n-1];
    for(int i=0;i<n-1;i++){
        ans1^=v1[i];
        ans1^=v2[i];
    }
    int ans2=v2[n-2];
    for(int i=0;i<n-2;i++){
        ans2^=v2[i];
        ans2^=v3[i];
    }
    cout<<ans1<<" "<<ans2<<endl;
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