#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1e9+7;
void solve()
{ 
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int mult=26;
    int ans=s[0]-'A'+1;
    for(int i=1;i<s.size();i++){
        int temp=(s[i]-'A' +1)*mult%mod;
        ans=(ans+temp)%mod;
        mult*=26;
        mult%=mod;
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