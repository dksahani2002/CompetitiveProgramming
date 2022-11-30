#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int ty,n;
    cin>>ty>>n;
    if(ty==1){
        for(int i=1;i*i<=n;i++){
            if(i*i==n){
                cout<<"YES\n";
                return;
            }
        }
    }else{
        for(int i=1;i*i*i<=n;i++){
            if(i*i*i==n){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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