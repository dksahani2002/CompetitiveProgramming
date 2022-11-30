#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
bool cmp(pair<int,int>&a, pair<int,int>&b){
    return (a.first-a.second)>(b.first-b.second);
}
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=v[i].second;
    }
    ans+=v[n-1].first- v[n-1].second;
    // cout<<endl;
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