#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>v;
void solve()
{
    int n;cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int l=0,r=n-1;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]<v[0]){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
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