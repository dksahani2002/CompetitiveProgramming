#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int BS(int a, int b, int mod){
    int ans=1;
    
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
void solve()
{
    int a,b,c,p;
    cin>>a>>b>>c>>p;
    if(b==0 && c!=0){
        cout<<1<<endl;
        return;
    }
    if(a==0 || a%p==0){
        cout<<0<<endl;
        return;
    }
    cout<<BS(a,BS(b,c,p-1),p)<<endl;
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