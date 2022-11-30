#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<int>v1(n),v2(m),v3(k);
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<m;i++)cin>>v2[i];
    for(int i=0;i<k;i++)cin>>v3[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    int ans=0;
    for(int i=0;i<m;i++){
        int temp=0;
        temp+=(lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin());
        temp*=(v3.end()-upper_bound(v3.begin(),v3.end(),v2[i]));
        ans+=temp;
    }
    cout<<ans<<endl;
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