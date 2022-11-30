#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n),q(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>q[i];
    map<pair<int,int>,int>mp;
    int ans=0,res=0;
    for(int i=0;i<n;i++){
        int x,y;
        if(v[i]){
            x=-q[i]/v[i];
            y=(-q[i]+v[i])%v[i];
        }else{
            if(q[i]==0)res++;
            continue;
        }
        mp[{x,y}]++;
        ans=max(ans,mp[{x,y}]);
    }
    cout<<ans+res<<endl;

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