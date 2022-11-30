#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];


    
    int ans=0;
    for(int i=0;i<32;i++){
        int cnt=0,cnt2=0;
        for(auto &x:v){
            if(x%2==1){
                 cnt++;
            }else{
                cnt2++;
            } 
            x/=2;
        }
        ans+=cnt*cnt2*pow(2,i);
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