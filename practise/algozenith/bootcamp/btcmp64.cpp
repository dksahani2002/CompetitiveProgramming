#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=v[n-1]-v[0];
    int l=v[0]+k;
    int r=v[n-1]-k;
    for(int i=0;i<n-1;i++){
        int maxi=max(v[i]+k,r);
        int mini=min(v[i+1]-k,l);
        ans=min(ans,maxi-mini);
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