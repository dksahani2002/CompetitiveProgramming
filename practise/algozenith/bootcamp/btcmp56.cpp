#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    int c5=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        while(v[i] && v[i]%5==0){
            v[i]/=5;
            c5++;
        }
    }
    for(int i=0;i<n;i++){
        while(c5 && v[i] && v[i]%2==0){
            c5--;
            v[i]/=2;
        }
    }
    int ans=1;
    if(c5)ans=5;
    for(auto x:v){
        ans=(ans*x%10)%10;
    }
    if(ans){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}