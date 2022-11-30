#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    int b;cin>>b;
    int v[n];
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n);
    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        if(sum+v[i]>b){
            cout<<i<<endl;
            return;
        }else{
            ans++;
            sum+=v[i];
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