#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,target;cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=1e18;
    sort(v.begin(),v.end());

    for(int i=1;i<n-1;i++){
        int l=0,r=n-1;
        while(1){
            if(l==i || r==i)break;
            int tri=v[r]+v[i]+v[l];
            ans=min(ans,abs(tri-target));
            if(tri>target)r--;
            else l++;
        }
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