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
    }
    int ans=0;
    int l=0,r=n-1;
    while(l<r){
        int temp=min(v[l],v[r])*abs(l-r);
        ans=max(ans,temp);
        if(v[l]<=v[r])l++;
        else r--;
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