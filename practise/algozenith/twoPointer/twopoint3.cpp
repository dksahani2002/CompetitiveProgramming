#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    map<int,int>mp;
    int ans=1e9;
    int i=0;
    for(int j=0;j<n;j++){
        mp[v[j]]++;
         while((j-i+1)>k){
            if(mp[v[i]]==1)mp.erase(v[i]);
            else mp[v[i]]--;
            i++;
         }
       if((j-i+1)==k) ans=min(ans,(int)mp.size());
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