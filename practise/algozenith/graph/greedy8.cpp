#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k,ans=0;cin>>n>>k;
    vector<int>v(n),sf(n);
    for(int i=0;i<n;i++)cin>>v[i];
     int cur=v[0];

    for(int i=1;i<n;i++){
         if(v[i]<cur){
            cur=v[i];
         }else if(v[i]>cur+k){
            ans+=v[i]-cur-k;
            cur=v[i]-k;
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