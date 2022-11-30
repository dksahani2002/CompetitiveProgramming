#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    map<int,int>mp;
    int ans=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(mp.count(v[i])){
            while(v[l]!=v[i]){
                mp.erase(v[l]);
                l++;
            }
            mp.erase(v[l]);
            l++;
        }
        mp[v[i]]++;
        ans=max(ans,(int)mp.size());
    }
    ans=max(ans,(int)mp.size());
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