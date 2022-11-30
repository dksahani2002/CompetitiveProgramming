#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
         int x,y;cin>>x>>y;
         v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    int ans=0,prev=-1e9;
    for(int i=0;i<n;i++){
         int r=v[i].first;
         int l=v[i].second;
         if(l>prev){
            ans++;
            prev=r;
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